#
# Copyright (c) 2026 atenfyr
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
# The license also applies to the adjacent "dump_modifiers.json" file.
# The license does not apply to any other files in this repository unless otherwise stated.
#

import sys, shutil, os, json, glob, re
from pathlib import Path

modifiers = None
with open('dump_modifiers.json', 'r') as f:
    modifiers = json.load(f)

MODULES_TO_INCLUDE = modifiers["STATICS"]["MODULES_TO_INCLUDE"]
BANNED_MODULES = modifiers["STATICS"]["BANNED_MODULES"]
FORCE_BAN_NAMES_WHEN_IMPORTED = modifiers["STATICS"]["FORCE_BAN_NAMES_WHEN_IMPORTED"]
FORCE_BAN_NAMES = modifiers["STATICS"]["FORCE_BAN_NAMES"]
DELETE_ALL_FILES_CONTAINING_IN_TITLE = modifiers["STATICS"]["DELETE_ALL_FILES_CONTAINING_IN_TITLE"]
REMOVE_BP_ACCESS = modifiers["STATICS"]["REMOVE_BP_ACCESS"]

FORCE_BAN_NAMES = FORCE_BAN_NAMES + DELETE_ALL_FILES_CONTAINING_IN_TITLE

LIST_UHT_TOKENS = ["UFUNCTION", "UPROPERTY", "UENUM", "UDELEGATE", "UCLASS"]

CROSS_MODULE_REF_REGEX = re.compile(r'-ModuleName=(\S+)\s+-ObjectName=(\S+)', )
def update_modifier_to_delete_invalid_includes(file_path, modifier):
    with open(file_path, 'r') as file_handle:
        while line := file_handle.readline():
            if not line or len(line) < 2 or line.isspace() or line[0] == "#": continue
            if not line.startswith("//CROSS-MODULE"): break
            names = re.search(CROSS_MODULE_REF_REGEX, line).group(1, 2)
            if not names[0] or not names[1]: continue

            if names[0] in BANNED_MODULES or names[1] in FORCE_BAN_NAMES_WHEN_IMPORTED:
                modifier[names[1]] = {"DELETE": True}

def process_modifiers(file_path, file_data, modifier):
    if not modifier:
        return
    
    file_name = Path(file_path).stem

    addAdvancedDisplayToAll = False

    # iterate through every line searching for places to make changes
    i = 0
    while i < len(file_data): # we avoid using a for loop so that we compute len every time
        line_data = file_data[i]
        for criterion in modifier:
            if criterion in line_data:
                this_modifier_data = modifier[criterion]
                if isinstance(this_modifier_data, str):
                    if not ("!ADVANCED!" in this_modifier_data):
                        addAdvancedDisplayToAll = True
                        file_data[i - 1] = file_data[i - 1].replace("(BlueprintReadWrite, ", "(SimpleDisplay, BlueprintReadWrite, ")
                        file_data[i - 1] = file_data[i - 1].replace("(BlueprintAssignable, ", "(SimpleDisplay, BlueprintAssignable, ")
                    this_modifier_data = this_modifier_data.replace("!ADVANCED!", "")

                    # count num spaces
                    num_spaces = 0
                    for n in range(15):
                        if n >= len(line_data):
                            break
                        elif line_data[n] == " ":
                            num_spaces += 1
                        else:
                            break
                    
                    file_data.insert(i, (" " * num_spaces) + "// " + this_modifier_data + "\n")
                    i += 1
                elif isinstance(this_modifier_data, dict):
                    # special cases
                    if "UMETA" in this_modifier_data:
                        dat2 = line_data.strip('\n').split(",")
                        if dat2[-1] != "": dat2.append("") # just in case we don't have a trailing comma in the line
                        file_data[i] = ",".join(dat2[:-1]) + " UMETA(" + this_modifier_data["UMETA"] + "),\n"
                    if "DELETE" in this_modifier_data:
                        if criterion == file_name:
                            try:
                                os.remove(file_path)
                            finally:
                                return
                        delete_start_relative_to_this = 0
                        delete_end_relative_to_this = 0
                        if this_modifier_data["DELETE"] is True:
                            delete_start_relative_to_this = 0
                            delete_end_relative_to_this = 0

                            if file_path.endswith(".cpp"):
                                delete_start_relative_to_this = 0
                                delete_end_relative_to_this = 0
                                ln = file_data[i]
                                if ln[0] != " " and ln.strip()[-1] == "{":
                                    try:
                                        while ln[0] != "}" and ln.strip() != "//}":
                                            delete_end_relative_to_this += 1
                                            ln = file_data[i + delete_end_relative_to_this]
                                    except:
                                        print("".join(file_data))
                                        print(i)
                            else:
                                for token in LIST_UHT_TOKENS:
                                    if token in file_data[i - 1]:
                                        delete_start_relative_to_this = -1
                                        break
                        else:
                            delete_start_relative_to_this = this_modifier_data["DELETE"][0] # inclusive
                            delete_end_relative_to_this = this_modifier_data["DELETE"][1] # inclusive
                        for n in range(delete_start_relative_to_this, delete_end_relative_to_this + 1):
                            if len(file_data[i + n]) >= 2 and file_data[i + n][:2] == "//": continue
                            file_data[i + n] = "//" + file_data[i + n]
                    if "SUBSTITUTE" in this_modifier_data:
                        file_data[i] = file_data[i].replace(criterion, this_modifier_data["SUBSTITUTE"])
                    if "SUBSTITUTE_LINE" in this_modifier_data:
                        file_data[i] = this_modifier_data["SUBSTITUTE_LINE"]
                    if "REMOVE_BP_ACCESS" in this_modifier_data:
                        file_data[i - 1] = file_data[i - 1].replace("BlueprintReadWrite, ", "").replace("BlueprintReadWrite)", ")").replace("BlueprintCallable, ", "").replace("BlueprintCallable)", ")")
                else:
                    raise Exception("Unexpected type for comment data: " + str(type(this_modifier_data)))
        i += 1
    
    if addAdvancedDisplayToAll:
        i = 0
        while i < len(file_data): # we avoid using a for loop so that we compute len every time
            file_data[i] = file_data[i].replace("(BlueprintReadWrite, ", "(AdvancedDisplay, BlueprintReadWrite, ")
            file_data[i] = file_data[i].replace("(BlueprintAssignable, ", "(AdvancedDisplay, BlueprintAssignable, ")
            i += 1

    with open(file_path, 'w') as file_handle:
        file_handle.write(''.join(file_data)) # new lines already in the strings

def process(dump_path, log = False):
    global FORCE_BAN_NAMES

    if log: print("Extracting source directories from dump")
    for folder in MODULES_TO_INCLUDE:
        try:
            shutil.rmtree(os.path.join(".", "Source", folder))
        except:
            pass
        shutil.copytree(os.path.join(dump_path, "Source", folder), os.path.join(".", "Source", folder))

    # also, ban classes specified within banned modules
    for folder in BANNED_MODULES:
        try:
            classes_within_module = [Path(pth).stem for pth in glob.glob(os.path.join(dump_path, "Source", folder, "**", "*.h"), recursive=True)]
            #print(classes_within_module)
            FORCE_BAN_NAMES += classes_within_module
        except:
            pass

    if log: print("Deleting excluded files")
    pathlist = glob.glob(os.path.join(".", "Source", "**", "*.h"), recursive=True) + glob.glob(os.path.join(".", "Source", "**", "*.cpp"), recursive=True)
    for file_path in pathlist:
        file_name = Path(file_path).stem
        for criterion in DELETE_ALL_FILES_CONTAINING_IN_TITLE:
            if criterion in file_name:
                try:
                    os.remove(file_path)
                except:
                    pass

    if log: print("Processing modifiers")
    pathlist = glob.glob(os.path.join(".", "Source", "**", "*.h"), recursive=True) + glob.glob(os.path.join(".", "Source", "**", "*.cpp"), recursive=True)
    global_modifier = modifiers["GLOBAL_MODIFIER"] if ("GLOBAL_MODIFIER" in modifiers) else {}
    for name in FORCE_BAN_NAMES:
        global_modifier[name] = {"DELETE": True}
    for name in REMOVE_BP_ACCESS:
        global_modifier[name] = {"REMOVE_BP_ACCESS": True}

    for file_path in pathlist:
        file_name = Path(file_path).stem

        this_modifier = None
        if file_name in modifiers:
            # merge with global modifier
            # specific modifier takes priority
            this_modifier = global_modifier | modifiers[file_name]
        else:
            this_modifier = global_modifier
        
        update_modifier_to_delete_invalid_includes(file_path, this_modifier)

        if this_modifier:
            file_data = []
            with open(file_path, 'r') as file_handle:
                file_data = file_handle.readlines()
            process_modifiers(file_path, file_data, this_modifier)

    # modify *.Build.cs files to remove dependencies on banned modules
    # also, manually remove "Astro" dependency from MessageOfTheDay.Build.cs to prevent circular dependency
    if log: print("Correcting *.Build.cs files")
    pathlist2 = glob.glob(os.path.join(".", "Source", "**", "*.Build.cs"), recursive=True)
    for file_path in pathlist2:
        isMOTD = ("MessageOfTheDay.Build.cs" in file_path)
        with open(file_path, 'r') as file_handle:
            file_data = file_handle.readlines()
        i = 0
        while i < len(file_data): # we avoid using a for loop so that we compute len every time
            for banned_module in BANNED_MODULES:
                if banned_module in file_data[i] or (isMOTD and "\"Astro\"" in file_data[i]):
                    del file_data[i]
                    i -= 1
                    break
            i += 1

        with open(file_path, 'w') as file_handle:
            file_handle.write(''.join(file_data)) # \n characters are already in the strings  

    if log: print("All done!")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python " + sys.argv[0] + " <path to UE4SS UHTHeaderDump folder>")
    else:
        process(' '.join(sys.argv[1:]), True)
