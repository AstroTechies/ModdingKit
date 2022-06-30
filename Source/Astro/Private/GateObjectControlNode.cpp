#include "GateObjectControlNode.h"

FGateObjectControlNode::FGateObjectControlNode() {
    this->GateObjectType = EGateObjectType::Chamber;
    this->Index = 0;
    this->RelativeOffsetSolarScalar = 0.00f;
    this->NodeMesh = NULL;
    this->TooltipComponent = NULL;
    this->IndicatorDefinition = NULL;
}

