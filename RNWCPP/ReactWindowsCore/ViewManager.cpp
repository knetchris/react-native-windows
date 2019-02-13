// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "ViewManager.h"

using namespace std;
using namespace folly;

namespace facebook { namespace react {

dynamic ViewManagerBase::GetConstants() const
{
	folly::dynamic constants = dynamic::object("Constants", GetExportedViewConstants())
		("Commands", GetCommands())
		("NativeProps", GetNativeProps());

	const auto bubblingEventTypesConstants = GetExportedCustomBubblingEventTypeConstants();
	if (bubblingEventTypesConstants.size())
		constants["bubblingEventTypes"] = bubblingEventTypesConstants;
	const auto directEventTypesConstants = GetExportedCustomDirectEventTypeConstants();
	if (directEventTypesConstants.size())
		constants["directEventTypes"] = directEventTypesConstants;

	return constants;
}

}}