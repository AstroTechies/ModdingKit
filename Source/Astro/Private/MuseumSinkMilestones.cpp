#include "MuseumSinkMilestones.h"

UMuseumSinkMilestones::UMuseumSinkMilestones() {
}

bool UMuseumSinkMilestones::IsValidMilestoneIndex(const uint8 inIndex) const {
    return false;
}

uint8 UMuseumSinkMilestones::GetNumberOfMilestones() const {
    return 0;
}

FMuseumMilestone UMuseumSinkMilestones::GetMilestoneAtIndex(const uint8 inIndex) const {
    return FMuseumMilestone{};
}


