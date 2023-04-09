//header for character
#ifndef MAINOBJECT_H
#define MAINOBJECT_H

#include "CommonFunc.h"
#include "BaseObject.h"
#include "BulletObject.h"
#include <vector>

#define GRAVITY_SPEED 0.9
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 15
#define PLAYER_JUMP_VAL 20

class MainObject : public BaseObject 
{
    public:
        MainObject();
        ~MainObject();

        enum WalkType {
            IDLE = 0,
            WALK_RIGHT = 1,
            WALK_LEFT = 2,
            JUMP = 3
        };
        enum WeaponType {
            SWORD = 10,
            BOW = 11
        };

        bool LoadImg(std::string path, SDL_Renderer* screen);
        void Show(SDL_Renderer* des);
        void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
        void set_clips();

        void DoPlayer(Map& map_data);
        void CheckToMap(Map& map_data);
        void SetMapXY(const int map_x, const int map_y) { map_x_ = map_x; map_y_ = map_y; }
        void CenterEntityOnMap(Map& map_data);
        void UpdateImagePlayer(SDL_Renderer* des);
        void HandleBullet(SDL_Renderer* des);
        SDL_Rect GetRectFrame();

        void set_bullet_list(std::vector<BulletObject*> bullet_list)
        {
            p_bullet_list_ = bullet_list;
        }
        std::vector<BulletObject*> p_bullet_list() const { return p_bullet_list_; }


    private:
        std::vector<BulletObject*> p_bullet_list_;
        float x_val_;
        float y_val_;

        float x_pos_;
        float y_pos_;

        int width_frame_;
        int height_frame_;

        SDL_Rect frame_clip_[6];
        Input input_type_;
        int frame_;
        int status_;
        int weapon_;
        bool on_ground_;

        int map_x_;
        int map_y_;

        int come_back_time_;
};

#endif // MAINOBJECT_H
