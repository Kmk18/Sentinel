#include "stdafx.h"
#include "BulletObject.h"


BulletObject::BulletObject()
{
	x_val_ = 0;
	x_val_ = 0;
	is_move_ = false;
	bullet_type_ = LASER;
}

BulletObject::~BulletObject()
{

}

void BulletObject::LoadBullet(SDL_Renderer* des)
{
	if (bullet_type_ == SPHERE_BULLET)
	{
		LoadImg("img//sphere_bullet.png", des);
	}
	else if (bullet_type_ == LASER)
	{
		LoadImg("img//laser.png", des);
	}
}

void BulletObject::HandleMove(const int& x_border, const int& y_border)
{
	if (bullet_dir_ == DIR_RIGHT)
	{
		rect_.x += x_val_;
		if (rect_.x > x_border)
		{
			is_move_ = false;
		}
	}
	else if (bullet_dir_ == DIR_LEFT)
	{
		rect_.x -= x_val_;
		if (rect_.x < 0)
		{
			is_move_ = false;
		}
	}
	else if (bullet_dir_ == DIR_UP)
	{
		rect_.y -= y_val_;
		if (rect_.y < 0)
		{
			is_move_ = false;
		}
	}
	else if (bullet_dir_ == DIR_UP_LEFT)
	{
		rect_.y -= y_val_;
		if (rect_.y < 0)
		{
			is_move_ = false;
		}
		rect_.x -= x_val_;
		if (rect_.x < 0)
		{
			is_move_ = false;
		}
	}
	else if (bullet_dir_ == DIR_UP_RIGHT)
	{
		rect_.x += x_val_;
		if (rect_.x > x_border)
		{
			is_move_ = false;
		}
		rect_.y -= y_val_;
		if (rect_.y < 0)
		{
			is_move_ = false;
		}
	}
	else if (bullet_dir_ == DIR_DOWN_LEFT)
	{
		rect_.y += y_val_;
		if (rect_.y > y_border)
		{
			is_move_ = false;
		}
		rect_.x -= x_val_;
		if (rect_.x < 0)
		{
			is_move_ = false;
		}
	}
	else if (bullet_dir_ == DIR_DOWN_RIGHT)
	{
		rect_.y += y_val_;
		if (rect_.y > y_border)
		{
			is_move_ = false;
		}
		rect_.x += x_val_;
		if (rect_.x > x_border)
		{
			is_move_ = false;
		}
	}
}