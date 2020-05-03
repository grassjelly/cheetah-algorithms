#ifndef ROBOTVIZ_H
#define ROBOTVIZ_H
//#include "quadruped_base/quadruped_leg.h"
#include "Eigen/Dense"

class RobotViz
{
	xpl::lines *line_;
	Eigen::Vector3d knee_;
	Eigen::Vector3d foot_;
	
	public:
		RobotViz(xpl::lines &line):
			line_(&line),
			knee_{0, 0, -0.141},
			foot_{0, 0, -0.141}
		{
			//line_->x = std::vector<double>({0.0, 0.5, 1.0, 1.1, 1.2, 1.3});
			//line_->y = std::vector<double>({0.0, 0.7, 0.5, 1.1, 1.2, 1.2});
			updateJoints(0,0);
		}
		
		Eigen::Vector3d rotate(const Eigen::Vector3d pos, const float alpha, const float phi, const float beta)
		{
		    Eigen::Matrix3d Rx;
		    Eigen::Matrix3d Ry;
		    Eigen::Matrix3d Rz;
		    Eigen::Vector3d xformed_pos;
		
		    Rz << cos(beta), -sin(beta), 0, sin(beta), cos(beta), 0, 0, 0, 1;
		    xformed_pos = (Rz * pos).eval();
		
		    Ry << cos(phi), 0, sin(phi), 0, 1, 0, -sin(phi), 0, cos(phi);
		    xformed_pos = (Ry * xformed_pos).eval();
		
		    Rx << 1, 0, 0, 0, cos(alpha), -sin(alpha), 0, sin(alpha),  cos(alpha);
		    xformed_pos = (Rx * xformed_pos).eval();
		
		    return xformed_pos;
		}
		
		void updateJoints(float upper_leg, float lower_leg)
		{
			Eigen::Vector3d new_knee;
			
			new_knee = knee_;
			new_knee = rotate(new_knee, 0, upper_leg, 0);
			//Eigen::Matrix3d Ry ;
			//Ry << cos(upper_leg), 0, sin(upper_leg), 0, 1, 0, -sin(upper_leg), 0, cos(upper_leg);
		    //new_knee = (Ry * new_knee).eval();
		
			
			Eigen::Vector3d new_foot;
			//new_foot += new_knee;
			//new_foot = rotate(new_foot, 0, lower_leg, 0);
			new_foot = foot_;
			new_foot = rotate(new_foot, 0, lower_leg, 0);
			new_foot += knee_;
			new_foot = rotate(new_foot, 0, upper_leg,0);
			
			line_->x = std::vector<double>({0, new_knee[0], new_foot[0]});
			line_->y = std::vector<double>({0, new_knee[2], new_foot[2]});
		}
		
};

#endif 