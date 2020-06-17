/*
 *  Resonant Amp tube amplifier simulation
 *  Copyright (C) 2020  Garrin McGoldrick
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <JuceHeader.h>

#include "../Utils.h"
#include "ParameterGroup.h"
#include "RSliderLabel.h"

class PowerAmpGroup : public ParameterGroup
{
public:
	PowerAmpGroup();
	~PowerAmpGroup() {}

	void setHeight(int height) { setSize(0, height); }
	void resized() override;

	void attachVTS(AudioProcessorValueTreeState& vts);

private:
	RSliderLabel sliderDrive;
	RSliderLabel sliderTight;
	RSliderLabel sliderGrit;
	RSliderLabel sliderSag;

	std::unique_ptr<SliderAttachment> attDrive;
	std::unique_ptr<SliderAttachment> attTight;
	std::unique_ptr<SliderAttachment> attGrit;
	std::unique_ptr<SliderAttachment> attSag;

	DISABLE_COMPONENT_RESIZE()
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PowerAmpGroup)
};
