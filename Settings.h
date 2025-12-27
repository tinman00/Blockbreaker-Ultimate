#pragma once

const int FRAMES_PER_SEC = 240;
const float FRAME_TIME = 1.f / FRAMES_PER_SEC;
const int BOUNDARY_THICKNESS = 20;
const int RACKET_Y_POS_TO_BOTTOM = 120;
const int RACKET_WIDTH = 150;
const int RACKET_HEIGHT = 30;
const float RACKET_SPEED = 1000.f;
const float BALL_RADIUS = 14.f;
const float BALL_SPEED = 600.f;
const float BALL_HANG_HEIGHT = 40.f;
const float BLOCK_WIDTH = 70.f;
const float BLOCK_HEIGHT = 35.f;
const int FRAGILE_BLOCK_SCORE = 10;
const int HARD_BLOCK_SCORE = 50;
const float HIDE_FORBBIDEN_ZONE_HEIGHT = 200.f;
const float LEVEL_INFO_WIDTH = 300.f;
const float UI_OFFSET_X = 40.f;
const int INITIAL_LIVES = 3;
const int SKILL_DROP_CHANCE_PERCENT = 60;
const float SKILL_FALLING_SPEED = 200.f;
const float SKILL_SIZE = 30.f;
const int MAX_BALL_COUNT = 100;
const int PAUSE_ICON_SIZE = 300;

void InitializeSettings();

void UpdateSettings();