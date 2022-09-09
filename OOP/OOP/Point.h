class Point
{
private:
	int x;

	int y;

public:

	Point();

	Point(int x, int y);

	int getX();

	int getY();

	void setX(int value);

	void setY(int value);

	double distance(Point destination);
};