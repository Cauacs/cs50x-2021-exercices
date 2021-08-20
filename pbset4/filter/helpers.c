#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    //looping through the image
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int avg = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3;

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{


    for(int i = 0; i < height; i++)
    {
        RGBTRIPLE buffer[width];

        for(int j = 0; j < width; j++)
        {
            buffer[width - j].rgbtRed = image[i][j].rgbtRed;
            buffer[width - j].rgbtGreen = image[i][j].rgbtGreen;
            buffer[width - j].rgbtBlue = image[i][j].rgbtBlue;
        }

        for(int n = 0; n < width; n++)
        {
            image[i][n].rgbtRed = buffer[n].rgbtRed;
            image[i][n].rgbtGreen = buffer[n].rgbtGreen;
            image[i][n].rgbtBlue = buffer[n].rgbtBlue;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE nimage[height][width];
    int avgred;
    int avggreen;
    int avgblue;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(i == 0 && j == 0)
            {
                avgred = 0;
                avggreen = 0;
                avgblue = 0;

                for(int n = 0; n < 2; n++)
                {
                    for(int m = 0; m < 2; m++)
                    {
                        avgred += image[n][m].rgbtRed ;
                        avggreen += image[n][m].rgbtGreen;
                        avgblue += image[n][m].rgbtBlue;
                    }

                avgred = avgred / 4;
                avggreen = avggreen / 4;
                avgblue = avgblue / 4;

                nimage[i][j].rgbtRed = avgred;
                nimage[i][j].rgbtGreen = avggreen;
                nimage[i][j].rgbtBlue = avgblue;
                }

            }


            else if(i == 0 && j == width - 1)
            {
                avgred = 0;
                avggreen = 0;
                avgblue = 0;

                for(int n = i, ct = 0; ct < 2; n++, ct++)
                {
                    for(int m = j - 1, ct2 = 0; ct2 < 2; m++, ct2++)
                    {
                        avgred += image[n][m].rgbtRed;
                        avggreen += image[n][m].rgbtGreen;
                        avgblue += image[n][m].rgbtBlue;
                    }
                }

                avgred = avgred / 4;
                avggreen = avggreen / 4;
                avgblue = avgblue / 4;

                nimage[i][j].rgbtRed = avgred;
                nimage[i][j].rgbtGreen = avggreen;
                nimage[i][j].rgbtBlue = avgblue;

            }

            else if(i == height - 1  && j == 0)
            {

                avgred = 0;
                avggreen = 0;
                avgblue = 0;

                for(int n = i - 1, ct = 0; ct < 2; n++, ct++)
                {
                    for(int m = 0, ct2 = 0; ct2 < 2; m++, ct2++)
                    {
                        avgred += image[n][m].rgbtRed ;
                        avggreen += image[n][m].rgbtGreen;
                        avgblue += image[n][m].rgbtBlue;
                    }
                }

                avgred = avgred / 4;
                avggreen = avggreen / 4;
                avgblue = avgblue / 4;

                nimage[i][j].rgbtRed = avgred;
                nimage[i][j].rgbtGreen = avggreen;
                nimage[i][j].rgbtBlue = avgblue;

            }

            else if(i == height - 1 && j == width - 1)
            {
                avgred = 0;
                avggreen = 0;
                avgblue = 0;

                for(int n = i - 1, ct = 0; ct < 2; n++, ct++)
                {
                    for(int m = j - 1, ct2 = 0; ct2 < 2; n++, ct2++)
                    {
                        avgred += image[n][m].rgbtRed;
                        avggreen += image[n][m].rgbtGreen;
                        avgblue += image[n][m].rgbtBlue;
                    }
                }

                avgred = avgred / 4;
                avggreen = avggreen / 4;
                avgblue = avgblue / 4;

                nimage[i][j].rgbtRed = avgred;
                nimage[i][j].rgbtGreen = avggreen;
                nimage[i][j].rgbtBlue = avgblue;
            }

            else if(i == 0)
            {
                avgred = 0;
                avggreen = 0;
                avgblue = 0;

                for(int n = 0, ct = 0; ct < 2; n++, ct++)
                {
                    for(int m = j - 1, ct2 = 0; ct2 < 3; m++, ct2++)
                    {
                        avgred += image[n][m].rgbtRed;
                        avggreen += image[n][m].rgbtGreen;
                        avgblue += image[n][m].rgbtBlue;
                    }
                }

                avgred = avgred / 6;
                avggreen = avggreen / 6;
                avgblue = avgblue / 6;

                nimage[i][j].rgbtRed = avgred;
                nimage[i][j].rgbtGreen = avggreen;
                nimage[i][j].rgbtBlue = avgblue;
            }

            else if(j == 0)
            {
                avgred = 0;
                avggreen = 0;
                avgblue = 0;

                for(int n = i - 1, ct = 0; ct < 3; n++, ct++)
                {
                    for(int m = 0, ct2 = 0; ct2 < 2; m++, ct2++)
                    {
                        avgred += image[n][m].rgbtRed;
                        avggreen += image[n][m].rgbtGreen;
                        avgblue += image[n][m].rgbtBlue;
                    }
                }

                avgred = avgred / 6;
                avggreen = avggreen / 6;
                avgblue = avgblue / 6;

                nimage[i][j].rgbtRed = avgred;
                nimage[i][j].rgbtGreen = avggreen;
                nimage[i][j].rgbtBlue = avgblue;

            }

            else if(i == height - 1)
            {

                avgred = 0;
                avggreen = 0;
                avgblue = 0;

                for(int n = i - 1, ct = 0; ct < 2; n++, ct++)
                {
                    for(int m = j - 1, ct2 = 0; ct2 < 3; m++, ct2++)
                    {
                        avgred += image[n][m].rgbtRed;
                        avggreen += image[n][m].rgbtGreen;
                        avgblue += image[n][m].rgbtBlue;
                    }
                }

                avgred = avgred / 6;
                avggreen = avggreen / 6;
                avgblue = avgblue / 6;

                nimage[i][j].rgbtRed = avgred;
                nimage[i][j].rgbtGreen = avggreen;
                nimage[i][j].rgbtBlue = avgblue;
            }

            else if (j == width - 1)
            {
                avgred = 0;
                avggreen = 0;
                avgblue = 0;

                for(int n = i - 1, ct = 0; ct < 3; n++, ct++)
                {
                    for(int m = j - 1, ct2 = 0; ct2 < 2; m++, ct2++)
                    {
                        avgred += image[n][m].rgbtRed;
                        avggreen += image[n][m].rgbtGreen;
                        avgblue += image[n][m].rgbtBlue;
                    }
                }

                avgred = avgred / 6;
                avggreen = avggreen / 6;
                avgblue = avgblue / 6;

                nimage[i][j].rgbtRed = avgred;
                nimage[i][j].rgbtGreen = avggreen;
                nimage[i][j].rgbtBlue = avgblue;
            }

            else
            {
                avgred = 0;
                avgblue = 0;
                avggreen = 0;

                for(int n = i - 1, p = i + 2; n < p; n++)
                {
                    for(int m = j - 1, o = j + 2; m < o; m++)
                    {
                        avgred += image[n][m].rgbtRed;
                        avggreen += image[n][m].rgbtGreen;
                        avgblue += image[n][m].rgbtBlue;
                    }
                }
                avgred = avgred / 9;
                avggreen = avggreen / 9;
                avgblue = avgblue / 9;

                nimage[i][j].rgbtRed = avgred;
                nimage[i][j].rgbtGreen = avggreen;
                nimage[i][j].rgbtBlue = avgblue;
            }
        }

    }

        for(int a = 0; a < height; a++)
        {

            for(int b = 0; b < width; b++)
            {
                image[a][b].rgbtRed = nimage[a][b].rgbtRed;
                image[a][b].rgbtGreen = nimage[a][b].rgbtGreen;
                image[a][b].rgbtBlue = nimage[a][b].rgbtBlue;
            }
        }
    return;

}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE nimage[height][width];

    int gxvred;
    int gxvblue;
    int gxvgreen;
    int gyvred;
    int gyvblue;
    int gyvgreen;
    int fr;
    int fb;
    int fg;

    int gx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int gy[3][3] =
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };


    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {

            if(i == 0 && j == 0)
            {
                gxvred = 0;
                gxvblue = 0;
                gxvgreen = 0;
                gyvred = 0;
                gyvblue = 0;
                gyvgreen = 0;
                fr = 0;
                fb = 0;
                fg = 0;

                for(int n = 0, ct = 1; ct < 3; n++, ct++)
                {
                    for(int m = 0, ct2 = 1; ct2 < 3; m++, ct2++)
                    {
                        gxvred += image[n][m].rgbtRed * gx[ct][ct2];
                        gxvblue += image[n][m].rgbtBlue * gx[ct][ct2];
                        gxvgreen += image[n][m].rgbtGreen * gx[ct][ct2];

                        gyvred += image[n][m].rgbtRed * gy[ct][ct2];
                        gyvblue += image[n][m].rgbtBlue * gy[ct][ct2];
                        gyvgreen += image[n][m].rgbtGreen * gy[ct][ct2];
                    }
                }


                fr = sqrt((gxvred*gxvred) + (gyvred*gyvred));
                fb = sqrt((gxvblue*gxvblue) + (gyvblue*gyvblue));
                fg = sqrt((gxvgreen*gxvgreen) + (gyvgreen*gyvgreen));

                if(fr > 255)
                    fr = 255;

                if(fb > 255)
                    fb = 255;

                if(fg > 255)
                    fg = 255;

                nimage[i][j].rgbtRed = fr;
                nimage[i][j].rgbtBlue = fb;
                nimage[i][j].rgbtGreen = fg;
            }

            else if(i == 0 && j == width - 1)
            {
                gxvred = 0;
                gxvblue = 0;
                gxvgreen = 0;
                gyvred = 0;
                gyvblue = 0;
                gyvgreen = 0;
                fr = 0;
                fb = 0;
                fg = 0;

                for(int n = 0, ct = 1; ct < 3; n++, ct++)
                {
                    for(int m = j - 1, ct2 = 0; ct2 < 2; m++, ct2++)
                    {
                        gxvred += image[n][m].rgbtRed * gx[ct][ct2];
                        gxvblue += image[n][m].rgbtBlue * gx[ct][ct2];
                        gxvgreen += image[n][m].rgbtGreen * gx[ct][ct2];

                        gyvred += image[n][m].rgbtRed * gy[ct][ct2];
                        gyvblue += image[n][m].rgbtBlue * gy[ct][ct2];
                        gyvgreen += image[n][m].rgbtGreen * gy[ct][ct2];
                    }
                }


                fr = sqrt((gxvred*gxvred) + (gyvred*gyvred));
                fb = sqrt((gxvblue*gxvblue) + (gyvblue*gyvblue));
                fg = sqrt((gxvgreen*gxvgreen) + (gyvgreen*gyvgreen));

                if(fr > 255)
                    fr = 255;

                if(fb > 255)
                    fb = 255;

                if(fg > 255)
                    fg = 255;

                nimage[i][j].rgbtRed = fr;
                nimage[i][j].rgbtBlue = fb;
                nimage[i][j].rgbtGreen = fg;
            }

            else if(i == height - 1 && j == 0)
            {
                gxvred = 0;
                gxvblue = 0;
                gxvgreen = 0;
                gyvred = 0;
                gyvblue = 0;
                gyvgreen = 0;
                fr = 0;
                fb = 0;
                fg = 0;

                for(int n = i - 1, ct = 0; ct < 2; n++, ct++)
                {
                    for(int m = 0, ct2 = 1; ct2 < 3; m++, ct2++)
                    {
                        gxvred += image[n][m].rgbtRed * gx[ct][ct2];
                        gxvblue += image[n][m].rgbtBlue * gx[ct][ct2];
                        gxvgreen += image[n][m].rgbtGreen * gx[ct][ct2];

                        gyvred += image[n][m].rgbtRed * gy[ct][ct2];
                        gyvblue += image[n][m].rgbtBlue * gy[ct][ct2];
                        gyvgreen += image[n][m].rgbtGreen * gy[ct][ct2];

                    }
                }

                fr = sqrt((gxvred*gxvred) + (gyvred*gyvred));
                fb = sqrt((gxvblue*gxvblue) + (gyvblue*gyvblue));
                fg = sqrt((gxvgreen*gxvgreen) + (gyvgreen*gyvgreen));

                if(fr > 255)
                    fr = 255;

                if(fb > 255)
                    fb = 255;

                if(fg > 255)
                    fg = 255;

                nimage[i][j].rgbtRed = fr;
                nimage[i][j].rgbtBlue = fb;
                nimage[i][j].rgbtGreen = fg;
            }
            

            else if(i == height - 1 && width - 1)
            {
                gxvred = 0;
                gxvblue = 0;
                gxvgreen = 0;
                gyvred = 0;
                gyvblue = 0;
                gyvgreen = 0;
                fr = 0;
                fb = 0;
                fg = 0;

                for(int n = i - 1, ct = 0; ct < 2; n++, ct++)
                {
                    for(int m = j - 1, ct2 = 0; ct2 < 2; m++, ct2++)
                    {
                        gxvred += image[n][m].rgbtRed * gx[ct][ct2];
                        gxvblue += image[n][m].rgbtBlue * gx[ct][ct2];
                        gxvgreen += image[n][m].rgbtGreen * gx[ct][ct2];

                        gyvred += image[n][m].rgbtRed * gy[ct][ct2];
                        gyvblue += image[n][m].rgbtBlue * gy[ct][ct2];
                        gyvgreen += image[n][m].rgbtGreen * gy[ct][ct2];

                    }
                }

                fr = sqrt((gxvred*gxvred) + (gyvred*gyvred));
                fb = sqrt((gxvblue*gxvblue) + (gyvblue*gyvblue));
                fg = sqrt((gxvgreen*gxvgreen) + (gyvgreen*gyvgreen));

                if(fr > 255)
                    fr = 255;

                if(fb > 255)
                    fb = 255;

                if(fg > 255)
                    fg = 255;

                nimage[i][j].rgbtRed = fr;
                nimage[i][j].rgbtBlue = fb;
                nimage[i][j].rgbtGreen = fg;
            }

            else if(i == 0)
            {
                gxvred = 0;
                gxvblue = 0;
                gxvgreen = 0;
                gyvred = 0;
                gyvblue = 0;
                gyvgreen = 0;
                fr = 0;
                fb = 0;
                fg = 0;

                for(int n = 0, ct = 1; ct < 3; n++, ct++)
                {
                    for(int m = j - 1, ct2 = 0; ct2 < 3; m++, ct2++)
                    {
                        gxvred += image[n][m].rgbtRed * gx[ct][ct2];
                        gxvblue += image[n][m].rgbtBlue * gx[ct][ct2];
                        gxvgreen += image[n][m].rgbtGreen * gx[ct][ct2];

                        gyvred += image[n][m].rgbtRed * gy[ct][ct2];
                        gyvblue += image[n][m].rgbtBlue * gy[ct][ct2];
                        gyvgreen += image[n][m].rgbtGreen * gy[ct][ct2];

                    }
                }

                fr = sqrt((gxvred*gxvred) + (gyvred*gyvred));
                fb = sqrt((gxvblue*gxvblue) + (gyvblue*gyvblue));
                fg = sqrt((gxvgreen*gxvgreen) + (gyvgreen*gyvgreen));

                if(fr > 255)
                    fr = 255;

                if(fb > 255)
                    fb = 255;

                if(fg > 255)
                    fg = 255;

                nimage[i][j].rgbtRed = fr;
                nimage[i][j].rgbtBlue = fb;
                nimage[i][j].rgbtGreen = fg;
            }

            else if(j == 0)
            {
                gxvred = 0;
                gxvblue = 0;
                gxvgreen = 0;
                gyvred = 0;
                gyvblue = 0;
                gyvgreen = 0;
                fr = 0;
                fb = 0;
                fg = 0;

                for(int n = i - 1, ct = 0; ct < 3; n++, ct++)
                {
                    for(int m = 0, ct2 = 1; ct2 < 2; m++, ct2++)
                    {
                        gxvred += image[n][m].rgbtRed * gx[ct][ct2];
                        gxvblue += image[n][m].rgbtBlue * gx[ct][ct2];
                        gxvgreen += image[n][m].rgbtGreen * gx[ct][ct2];

                        gyvred += image[n][m].rgbtRed * gy[ct][ct2];
                        gyvblue += image[n][m].rgbtBlue * gy[ct][ct2];
                        gyvgreen += image[n][m].rgbtGreen * gy[ct][ct2];

                    }
                }

                fr = sqrt((gxvred*gxvred) + (gyvred*gyvred));
                fb = sqrt((gxvblue*gxvblue) + (gyvblue*gyvblue));
                fg = sqrt((gxvgreen*gxvgreen) + (gyvgreen*gyvgreen));

                if(fr > 255)
                    fr = 255;

                if(fb > 255)
                    fb = 255;

                if(fg > 255)
                    fg = 255;

                nimage[i][j].rgbtRed = fr;
                nimage[i][j].rgbtBlue = fb;
                nimage[i][j].rgbtGreen = fg;
            }

            else if(i == height - 1)
            {
                gxvred = 0;
                gxvblue = 0;
                gxvgreen = 0;
                gyvred = 0;
                gyvblue = 0;
                gyvgreen = 0;
                fr = 0;
                fb = 0;
                fg = 0;

                for(int n = i - 1, ct = 0; ct < 2; n++, ct++)
                {
                    for(int m = j - 1, ct2 = 0; ct2 < 3; m++, ct2++)
                    {
                        gxvred += image[n][m].rgbtRed * gx[ct][ct2];
                        gxvblue += image[n][m].rgbtBlue * gx[ct][ct2];
                        gxvgreen += image[n][m].rgbtGreen * gx[ct][ct2];

                        gyvred += image[n][m].rgbtRed * gy[ct][ct2];
                        gyvblue += image[n][m].rgbtBlue * gy[ct][ct2];
                        gyvgreen += image[n][m].rgbtGreen * gy[ct][ct2];

                    }
                }

                fr = sqrt((gxvred*gxvred) + (gyvred*gyvred));
                fb = sqrt((gxvblue*gxvblue) + (gyvblue*gyvblue));
                fg = sqrt((gxvgreen*gxvgreen) + (gyvgreen*gyvgreen));

                if(fr > 255)
                    fr = 255;

                if(fb > 255)
                    fb = 255;

                if(fg > 255)
                    fg = 255;

                nimage[i][j].rgbtRed = fr;
                nimage[i][j].rgbtBlue = fb;
                nimage[i][j].rgbtGreen = fg;
            }

            else if(j == width - 1)
            {
                gxvred = 0;
                gxvblue = 0;
                gxvgreen = 0;
                gyvred = 0;
                gyvblue = 0;
                gyvgreen = 0;
                fr = 0;
                fb = 0;
                fg = 0;

                for(int n = i - 1, ct = 0; ct < 3; n++, ct++)
                {
                    for(int m = j - 1, ct2 = 0; ct2 < 2; m++, ct2++)
                    {
                        gxvred += image[n][m].rgbtRed * gx[ct][ct2];
                        gxvblue += image[n][m].rgbtBlue * gx[ct][ct2];
                        gxvgreen += image[n][m].rgbtGreen * gx[ct][ct2];

                        gyvred += image[n][m].rgbtRed * gy[ct][ct2];
                        gyvblue += image[n][m].rgbtBlue * gy[ct][ct2];
                        gyvgreen += image[n][m].rgbtGreen * gy[ct][ct2];

                    }
                }

                fr = sqrt((gxvred*gxvred) + (gyvred*gyvred));
                fb = sqrt((gxvblue*gxvblue) + (gyvblue*gyvblue));
                fg = sqrt((gxvgreen*gxvgreen) + (gyvgreen*gyvgreen));

                if(fr > 255)
                    fr = 255;

                if(fb > 255)
                    fb = 255;

                if(fg > 255)
                    fg = 255;

                nimage[i][j].rgbtRed = fr;
                nimage[i][j].rgbtBlue = fb;
                nimage[i][j].rgbtGreen = fg;
            }

            else
            {
                gxvred = 0;
                gxvblue = 0;
                gxvgreen = 0;
                gyvred = 0;
                gyvblue = 0;
                gyvgreen = 0;
                fr = 0;
                fb = 0;
                fg = 0;

                for(int n = i - 1, ct = 0; ct < 3; n++, ct++)
                {
                    for(int m = j - 1, ct2 = 0; ct2 < 3; m++, ct2++)
                    {
                        gxvred += image[n][m].rgbtRed * gx[ct][ct2];
                        gxvblue += image[n][m].rgbtBlue * gx[ct][ct2];
                        gxvgreen += image[n][m].rgbtGreen * gx[ct][ct2];

                        gyvred += image[n][m].rgbtRed * gy[ct][ct2];
                        gyvblue += image[n][m].rgbtBlue * gy[ct][ct2];
                        gyvgreen += image[n][m].rgbtGreen * gy[ct][ct2];

                    }
                }

                fr = sqrt((gxvred*gxvred) + (gyvred*gyvred));
                fb = sqrt((gxvblue*gxvblue) + (gyvblue*gyvblue));
                fg = sqrt((gxvgreen*gxvgreen) + (gyvgreen*gyvgreen));

                if(fr > 255)
                    fr = 255;

                if(fb > 255)
                    fb = 255;

                if(fg > 255)
                    fg = 255;

                nimage[i][j].rgbtRed = fr;
                nimage[i][j].rgbtBlue = fb;
                nimage[i][j].rgbtGreen = fg;
            }

        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = nimage[i][j].rgbtRed;
            image[i][j].rgbtBlue = nimage[i][j].rgbtBlue;
            image[i][j].rgbtGreen = nimage[i][j].rgbtGreen;
        }
    }

    return;
}
