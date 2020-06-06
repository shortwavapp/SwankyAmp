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

struct RSliderDims {
	// the radius of the knob
	float radius = 0.0f;
	// the amount of space between the knob edge and the graphic edge
	float margin = 0.0f;
	// the gap between the knob and the dots in the margin
	float gap = 0.0f;
	// the largest angle of the knob, where it cuts away
	float theta = 0.0f;
	// the bounds of the graphic
	Rectangle<float> innerBounds;
	// the center of the knob
	Point<float> centre;
};

class RSlider : public Slider
{
public:
	RSlider();
	// NOTE: base class destructor is not virtual, so can't be using pointers to
	// an `RSlider` of type `Slider*` when deleting.
	~RSlider() {}

	String fmtSliderPos(float sliderPos) const;

	RSliderDims calculateDims() const;

	void setGap(float pGap) { gap = pGap; }
	void setMargin(float pMargin) { margin = pMargin; }
	void setPosMapLow(float value) { posMapLow = value; }
	void setPosMapHigh(float value) { posMapHigh = value; }
	void setPosMapFmt(const String& fmt) { posMapFmt = fmt; }

private:
	using Slider::setSliderStyle;
	using Slider::setTextBoxStyle;

	float posMapLow = 0.0f;
	float posMapHigh = 1.0f;
	String posMapFmt;

	float gap = 0.0f;
	float margin = 0.0f;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RSlider)
};