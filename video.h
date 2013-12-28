#ifndef __H_VIDEOS__
#define __H_VIDEOS__

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

bool   video_init(void);
void   video_close(void);
void   video_sync(void);

/* Drawing functions */
void   video_blank_screen(void);
void   video_put_pixel(int x, int y, Uint32 color);
Uint32 video_get_pixel(int x, int y);

/* Common color definitions */
extern Uint32 video_color_black;

#endif /* __H_VIDEOS__ */

