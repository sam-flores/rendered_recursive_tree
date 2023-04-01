#define tree 1

struct object
{
    int shape;
    double rgb[3];
    struct treenode *head;
    double TSR[4][4];
    double TSR_inverse[4][4];
};