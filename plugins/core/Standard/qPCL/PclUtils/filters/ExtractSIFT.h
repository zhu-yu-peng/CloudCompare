#pragma once

//##########################################################################
//#                                                                        #
//#                       CLOUDCOMPARE PLUGIN: qPCL                        #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU General Public License as published by  #
//#  the Free Software Foundation; version 2 or later of the License.      #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#                         COPYRIGHT: Luca Penasa                         #
//#                                                                        #
//##########################################################################

#include "BaseFilter.h"

//! SIFT keypoints extraction
class ExtractSIFT: public BaseFilter
{
public:
	ExtractSIFT();
	~ExtractSIFT() override;

protected:

	//inherited from BaseFilter
	int compute() override;
	bool checkSelected() const override;
	int getParametersFromDialog() override;
	QString getErrorMessage(int errorCode) const override;

	int checkParameters();

protected:
	int m_nr_octaves;
	float m_min_scale;
	int m_nr_scales_per_octave;
	float m_min_contrast;
	bool m_use_min_contrast;
	QString m_field_to_use;
	std::string m_field_to_use_no_space;

	enum Modes {RGB, SCALAR_FIELD};
	Modes m_mode;
};
