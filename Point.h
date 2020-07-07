struct Point
{
    float x;
    float y;
    Point(float x = 0, float y = 0)
    {
        this->x = x;
        this->y = y;
    }
    Point operator+(Point a)
    {
        Point temp;
        temp.x = this->x + a.x;
        temp.y = this->y + a.y;
        return temp;
    }
    Point operator-(Point a)
    {
        Point temp;
        temp.x = this->x - a.x;
        temp.y = this->y - a.y;
        return temp;
    }
    Point operator/(int t)
    {
        Point temp;
        temp.x = this->x / t;
        temp.y = this->y / t;
        return temp;
    }
    bool operator==(Point a)
    {
        return a.x == this->x && a.y == this->y;
    }
    Point set(float x, float y)
    {
        this->x = x;
        this->y = y;
        return *this;
    }
    Point toInt()
    {
        Point temp((int)x, (int)y);
        return temp;
    }