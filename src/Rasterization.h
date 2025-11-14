#pragma once
#include "Image.h"
#include "Mesh.h"

struct Rect
{
    int xMin;
    int xMax;
    int yMin;
    int yMax;
};

inline void DrawLineX(Image* image, int row, int x0, int x1, Color color)
{
    if (x1 < x0)
    {
        int temp = x0;
        x0 = x1;
        x1 = temp;
    }

    for (int x = x0; x <= x1; x++)
        SetPixel(image, x, row, color);
}

inline void DrawLineY(Image* image, int col, int y0, int y1, Color color)
{
    if (y1 < y0)
    {
        int temp = y0;
        y0 = y1;
        y1 = temp;
    }

    for (int y = y0; y <= y1; y++)
        SetPixel(image, col, y, color);
}

inline void DrawLine(Image* image, int x0, int y0, int x1, int y1, Color color)
{
    float dx = (float)x1 - (float)x0;
    float dy = (float)y1 - (float)y0;

    float steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);

    float xStep = dx / steps;
    float yStep = dy / steps;

    float x = (float)x0;
    float y = (float)y0;

    for (int i = 0; i <= steps; i++)
    {
        SetPixel(image, (int)x, (int)y, color);
        x += xStep;
        y += yStep;
    }
}

inline void DrawRect(Image* image, int x, int y, int w, int h, Color color)
{
    int xEnd = x + w;
    int yEnd = y + h;

    for (int yy = y; yy < yEnd; yy++)
        for (int xx = x; xx < xEnd; xx++)
            SetPixel(image, xx, yy, color);
}

inline void DrawRectLines(Image* image, int x, int y, int w, int h, Color color)
{
    int xEnd = x + w;
    int yEnd = y + h;

    DrawLineX(image, y, x, xEnd, color);
    DrawLineX(image, yEnd, x, xEnd, color);
    DrawLineY(image, x, y, yEnd, color);
    DrawLineY(image, xEnd, y, yEnd, color);
}

inline void DrawCircle(Image* image, int cx, int cy, int cr, Color color)
{
    int x = 0;
    int y = cr;
    int d = 3 - 2 * cr;

    auto line = [&](int lx, int ly, int l)
        {
            for (int dx = -l; dx <= l; dx++)
                SetPixel(image, lx + dx, ly, color);
        };

    while (y >= x)
    {
        line(cx, cy + y, x);
        line(cx, cy - y, x);
        line(cx, cy + x, y);
        line(cx, cy - x, y);

        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
        {
            d = d + 4 * x + 6;
        }
    }
}

inline void DrawCircleLines(Image* image, int cx, int cy, int cr, Color color)
{
    int x = 0;
    int y = cr;
    int d = 3 - 2 * cr;

    while (y >= x)
    {
        SetPixel(image, cx + x, cy + y, color);
        SetPixel(image, cx - x, cy + y, color);
        SetPixel(image, cx + x, cy - y, color);
        SetPixel(image, cx - x, cy - y, color);
        SetPixel(image, cx + y, cy + x, color);
        SetPixel(image, cx - y, cy + x, color);
        SetPixel(image, cx + y, cy - x, color);
        SetPixel(image, cx - y, cy - x, color);

        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
        {
            d = d + 4 * x + 6;
        }
    }
}
