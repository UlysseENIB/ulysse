#pragma once
#include "Global.h"

/*
Generic camera class by Nghia Ho
*/

class Camera
{
public:
	Camera() { Init(); }
	~Camera(){}

	void Init();
	void Refresh();
	void SetPos(float x, float y, float z);
    void GetPos(float &x, float &y, float &z);
    void GetDirectionVector(float &x, float &y, float &z);
	void SetYaw(float angle);
	void SetPitch(float angle);

	// Navigation
	void Move(float incr);
	void Strafe(float incr);
	void Fly(float incr);
	void RotateYaw(float angle);
	void RotatePitch(float angle);

private:
	float m_x =200, m_y=200, m_z=500;   // Position
    float m_lx= 0, m_ly=0, m_lz=-1; // Direction vector of where we are looking at
	float m_yaw, m_pitch; // Various rotation angles
	float m_strafe_lx, m_strafe_lz; // Always 90 degree to direction vector
};