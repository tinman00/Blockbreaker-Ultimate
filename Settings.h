#pragma once

const int FRAMES_PER_SEC = 160;
const int BOUNDARY_THICKNESS = 20;
const int RACKET_Y_POS_TO_BOTTOM = 120;
const int RACKET_WIDTH = 150;
const int RACKET_HEIGHT = 30;
const float RACKET_SPEED = 1000.f;
const float BALL_RADIUS = 14.f;
const float BALL_SPEED = 600.f;
const float BLOCK_WIDTH = 70.f;
const float BLOCK_HEIGHT = 35.f;
const float HIDE_FORBBIDEN_ZONE_HEIGHT = 200.f;
const float LEVEL_INFO_WIDTH = 300.f;
const float UI_OFFSET_X = 40.f;
const int INITIAL_LIVES = 3;

void InitializeSettings();

void UpdateSettings();