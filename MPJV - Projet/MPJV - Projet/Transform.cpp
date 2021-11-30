#include "Transform.h"

Transform::Transform(Entity* owner) : Component(owner)
{
	m_name = "Transform";
}

void Transform::setPosition(Vector3D position)
{
	m_position[0] = position.getX();
	m_position[1] = position.getY();
	m_position[2] = position.getZ();
}

void Transform::addPosition(Vector3D position)
{
	m_position[0] += position.getX();
	m_position[1] += position.getY();
	m_position[2] += position.getZ();
}

float* Transform::getPosition(){
	return m_position;
}

void Transform::setRotation(Vector3D rotation)
{
	m_rotation[0] = rotation.getX();
	m_rotation[1] = rotation.getY();
	m_rotation[2] = rotation.getZ();
}

void Transform::addRotation(Vector3D rotation)
{
	m_rotation[0] += rotation.getX();
	m_rotation[1] += rotation.getY();
	m_rotation[2] += rotation.getZ();
}

float* Transform::getRotation(){
	return m_rotation;
}

//void Transform::setScale(Vector3D scale){
//	m_scale = scale;
//}

float* Transform::getScale(){
	return m_scale;
}

void Transform::renderComponentUI()
{
	ImGui::DragFloat3("Position", m_position, 0.01f);
	ImGui::DragFloat3("Rotation", m_rotation, 0.01f);
	ImGui::DragFloat3("Scale", m_scale, 0.01f);
}
