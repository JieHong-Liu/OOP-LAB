class Point {
public:
	Point(); // constructor
	void Set(int vertical, int horizontal);
	void Move(int x, int y);
	void Rotate();
	int RetrieveVertical();
	int RetrieveHorizontal();
private:
	int vertical;
	int horizontal;
};