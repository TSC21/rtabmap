/*
Copyright (c) 2010-2014, Mathieu Labbe - IntRoLab - Universite de Sherbrooke
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Universite de Sherbrooke nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef ODOMETRYINFO_H_
#define ODOMETRYINFO_H_

#include <map>

namespace rtabmap {

class OdometryInfo
{
public:
	OdometryInfo() :
		lost(true),
		matches(-1),
		inliers(-1),
		variance(-1),
		features(-1),
		localMapSize(-1),
		timeEstimation(-1),
		stamp(0),
		interval(0),
		distanceTravelled(0),
		type(-1)
	{}
	bool lost;
	int matches;
	int inliers;
	float variance;
	int features;
	int localMapSize;
	float timeEstimation;
	float timeParticleFiltering;
	double stamp;
	double interval;
	Transform transform;
	Transform transformFiltered;
	float distanceTravelled;

	int type; // 0=BOW, 1=Optical Flow, 2=ICP

	// BOW odometry
	std::multimap<int, cv::KeyPoint> words;
	std::vector<int> wordMatches;
	std::vector<int> wordInliers;
	std::multimap<int, cv::Point3f> localMap;

	// Optical Flow odometry
	std::vector<cv::Point2f> refCorners;
	std::vector<cv::Point2f> newCorners;
	std::vector<int> cornerInliers;
};

}

#endif /* ODOMETRYINFO_H_ */
