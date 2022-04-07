#if !defined(UTILS_H)
#define UTILS_H

short rgb2short(unsigned char r, unsigned char g, unsigned char b);
void short2rgb(short color, unsigned char* r, unsigned char* g, unsigned char* b);

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// simple data types
typedef struct{
    int x;
    int y;
} Point2D;

typedef struct{
    int x;
    int y;
    int w;
    int h;
} Rect2D;

#endif // UTILS_H
