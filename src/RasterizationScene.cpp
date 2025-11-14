#include "RasterizationScene.h"
#include "Rasterization.h"
#include "ImageUtils.h"
#include "Camera.h"
#include "Time.h"

static Image fDiffuseMap;

void RasterizationScene::OnLoad()
{
    gCamera = FromView(LookAt({ 0.0f, 0.0f, 5.0f }, V3_ZERO, V3_UP));
    CreateImageFromFile(&fDiffuseMap, "assets/textures/african_head_diffuse.png", true);
}

void RasterizationScene::OnUnload()
{
    DestroyImage(&fDiffuseMap);
}

void RasterizationScene::OnUpdate(float dt)
{
    ClearColor(&gImageCPU, BLACK);

    DrawLine(&gImageCPU, 50, 50, 300, 300, WHITE);

    DrawRect(&gImageCPU, 200, 200, 150, 80, RED);
    DrawRectLines(&gImageCPU, 200, 200, 150, 80, GREEN);

    DrawRectLines(&gImageCPU, 0, 0, 120, 120, GREEN);

    DrawLineX(&gImageCPU, 420, 69, 390, BLUE);
    DrawLineY(&gImageCPU, 420, 69, 390, BLUE);
}
