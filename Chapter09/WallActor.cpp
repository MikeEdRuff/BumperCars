#include "WallActor.h"
#include "Game.h"
#include "Renderer.h"
#include "MeshComponent.h"

WallActor::WallActor(Game* game)
	:Actor(game)
{
	SetScale(100.0f);
	MeshComponent* mc = new MeshComponent(this);
	mc->SetMesh(GetGame()->GetRenderer()->GetMesh("Assets/Plane.gpmesh"));
}
