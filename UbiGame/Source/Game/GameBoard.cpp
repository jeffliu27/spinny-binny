#include "GameBoard.h"

#include "GameEngine\GameEngineMain.h"
#include "GameEngine\EntitySystem\Components\CollidableComponent.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"
#include "GameEngine\Helper\MathHelpers.h"
#include "GameEngine\Util\CameraManager.h"
#include "Game\GameEntities\PlayerEntity.h"
#include "Game\GameEntities\ProjectileEntity.h"

using namespace Game;

GameBoard::GameBoard()
	: m_lastProjectileSpawnTimer(0.f)
	, m_isGameOver(false)
	, m_player(nullptr)
	, m_backGround(nullptr)
{
	m_player = new PlayerEntity();
	
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
	m_player->SetPos(sf::Vector2f(50.f, 50.f));	
	m_player->SetSize(sf::Vector2f(40.f, 40.f));
	
	CreateBackGround();
	//Debug
	for (int a = 0; a < 3; ++a)
	{
		//SpawnNewRandomObstacles();
	}
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
	if (!m_isGameOver)
	{
		m_lastProjectileSpawnTimer -= dt;
		if (m_lastProjectileSpawnTimer <= 0.f)
		{
			SpawnNewRandomProjectiles();
			// SpawnNewRandomTiledObstacles();
		}

		UpdateProjectiles(dt);
		UpdateBackGround();
		UpdatePlayerDying();
	}		
}


void GameBoard::UpdateProjectiles(float dt)
{
	
	for (std::vector<GameEngine::Entity*>::iterator it = m_projectiles.begin(); it != m_projectiles.end();)
	{
		GameEngine::Entity* projectile = (*it);
		projectile->Update();
		//sf::Vector2f currPos = obstacle->GetPos();
		//currPos.x -= obstacleSpeed * dt;
		//obstacle->SetPos(currPos);
		//If we are to remove ourselves
		if (projectile->GetPos().x < -50.f)
		{
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(projectile);
			it = m_projectiles.erase(it);
		}
		else
		{
			it++;
		}
	}
}


void GameBoard::UpdatePlayerDying()
{	
	bool noGameOver = GameEngine::CameraManager::IsFollowCameraEnabled();

	if (noGameOver)
		return;

	static float xToPlayerDie = 0.f;
	if (m_player->GetPos().x < xToPlayerDie)
	{
		m_isGameOver = true;
	}
}


void GameBoard::SpawnNewRandomProjectiles()
{
	if (m_projectiles.size() > 0) return;
	static float minNextSpawnTime = 0.3f;
	static float maxNextSpawnTime = 0.7f;

	static float minObstacleXPos = 50.f;
	static float maxObstacleXPos = 450.f;
	static float minObstacleYPos = 20.f;
	static float maxObstacleYPos = 450.f;
	
	static float minObstacleHeight = 50.f;
	static float maxObstacleHeight = 170.f;
	static float minObstacleWidth = 20.f;
	static float maxObstacleWidth = 40.f;

	sf::Vector2f pos = sf::Vector2f(MathHelpers::RandFloatIn(minObstacleXPos, maxObstacleXPos), MathHelpers::RandFloatIn(minObstacleYPos, maxObstacleYPos));
	sf::Vector2f size = sf::Vector2f(MathHelpers::RandFloatIn(minObstacleWidth, maxObstacleWidth), MathHelpers::RandFloatIn(minObstacleHeight, maxObstacleHeight));

	SpawnNewProjectile(pos, size);

	m_lastProjectileSpawnTimer = MathHelpers::RandFloatIn(minNextSpawnTime, maxNextSpawnTime);
}


/* void GameBoard::SpawnNewRandomTiledObstacles()
{
	static int minObstacleCount = 2;
	static int maxObstacleCount = 7;

	static float minNextSpawnTime = 0.3f;
	static float maxNextSpawnTime = 0.7f;

	static float minObstacleXPos = 350.f;
	static float maxObstacleXPos = 450.f;
	static float minObstacleYPos = 20.f;
	static float maxObstacleYPos = 450.f;

	sf::Vector2f pos = sf::Vector2f(MathHelpers::RandFloatIn(minObstacleXPos, maxObstacleXPos), MathHelpers::RandFloatIn(minObstacleYPos, maxObstacleYPos));	
	sf::Vector2f size = sf::Vector2f(32.f, 32.f);

	int obstacleCount = (int)MathHelpers::RandFloatIn((float)minObstacleCount, (float)maxObstacleCount);
	for (int a = 0; a < obstacleCount; ++a)
	{
		SpawnNewObstacle(pos, size);
		pos.y += size.y;
	}

	m_lastObstacleSpawnTimer = MathHelpers::RandFloatIn(minNextSpawnTime, maxNextSpawnTime);
} */


void GameBoard::SpawnNewProjectile(const sf::Vector2f& pos, const sf::Vector2f& size)
{
	ProjectileEntity* projectile = new ProjectileEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(projectile);
	projectile->SetPos(pos);
	projectile->SetSize(sf::Vector2f(size.x, size.y));

	m_projectiles.push_back(projectile);
}


void GameBoard::CreateBackGround()
{
	GameEngine::Entity* bgEntity = new GameEngine::Entity();
	GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>(bgEntity->AddComponent<GameEngine::SpriteRenderComponent>());
	render->SetTexture(GameEngine::eTexture::BG);
	render->SetZLevel(0);
	bgEntity->SetPos(sf::Vector2f(250.f, 250.f));
	bgEntity->SetSize(sf::Vector2f(500.f, 500.f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bgEntity);

	m_backGround = bgEntity;
}


void GameBoard::UpdateBackGround()
{
	if (!m_backGround || !m_player)
		return;

	if (!GameEngine::CameraManager::IsFollowCameraEnabled())
		return;

	m_backGround->SetPos(m_player->GetPos());
}