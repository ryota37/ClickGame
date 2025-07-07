# include <Siv3D.hpp> // Siv3D v0.6.15

void Main()
{
	Circle circle{50,50,50};
	bool isAlive = true;

	while (System::Update())
	{
		if(isAlive) circle.draw();
		if (circle.leftClicked()) isAlive = false;
	}
}
