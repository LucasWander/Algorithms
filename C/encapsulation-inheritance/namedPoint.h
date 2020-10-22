struct NamedPoint;

struct NamedPoint* createNamedPoint(double x, double y, char *name);


void setName(struct NamedPoint *namedPoint,char *name);

char* getName(struct NamedPoint *namedPoint);
