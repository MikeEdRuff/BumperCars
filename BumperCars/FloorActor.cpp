#include "FloorActor.h"
#include "Game.h"
#include "Renderer.h"
#include "MeshComponent.h"

FloorActor::FloorActor(Game* game)
	:Actor(game)
{
	SetScale(2.3f); // Changed to scale - Carl
	MeshComponent* mc = new MeshComponent(this);
	mc->SetMesh(GetGame()->GetRenderer()->GetMesh("Assets/Plane.gpmesh"));
}
