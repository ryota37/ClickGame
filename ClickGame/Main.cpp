# include <Siv3D.hpp> // Siv3D v0.6.15

namespace Coordinate
{

	double TOP;
	double BOTTOM;
	double LEFT;
	double RIGHT;

	void Init()
	{
		TOP = 0.0;
		BOTTOM = Scene::Height();
		LEFT = 0.0;
		RIGHT = Scene::Width();
	}
};

class Ball
{
private:
	Circle m_circle;
	Vec2 m_velocity;
	bool m_isAlive;
public:
	Ball() :
		m_circle{RandomVec2(Scene::Rect()), 20},
		m_velocity{RandomVec2(3)},
		m_isAlive(true){}

	void update()
	{
		m_circle.x = m_circle.x + m_velocity.x;
		m_circle.y = m_circle.y + m_velocity.y;
	}

	void draw() const
	{
		if (m_isAlive) m_circle.draw(Palette::Orange);
	}

	void reflectOnWalls()
	{
		if (m_circle.left().x < Coordinate::LEFT || m_circle.right().x > Coordinate::RIGHT)
		{
			m_velocity.x *= -1;
		}
		if (m_circle.top().y < Coordinate::TOP || m_circle.bottom().y > Coordinate::BOTTOM)
		{
			m_velocity.y *= -1;
		}
	}

	void vanishWhenClicked()
	{
		if (m_circle.leftClicked()) m_isAlive = false;
	}

};


void Main()
{
	Coordinate::Init();

	Array<Ball> balls;

	for (int i = 0; i < 3; i++)
	{
		Ball ball;
		balls << ball;
	}

	while (System::Update())
	{
		for (auto& ball : balls)
		{
			ball.update();
			ball.draw();
			ball.vanishWhenClicked();
			ball.reflectOnWalls();
		}
	}
}
