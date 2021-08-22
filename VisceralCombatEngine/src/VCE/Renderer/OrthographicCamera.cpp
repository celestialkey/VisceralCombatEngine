#include "vcepch.h"
#include "OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace VCE {
	OrthographicCamera::OrthographicCamera(float l, float r, float b, float t) 
		: m_ProjectionMatrix(glm::ortho(l, r,b, t)), m_ViewMatrix(1.0f)
	{
		m_ViewProjectionMatrix = m_ViewMatrix * m_ProjectionMatrix;
	}

	void OrthographicCamera::RecalculateViewMatrix() {
		glm::mat4 transform =	glm::translate(glm::mat4(1.0f), m_Position) *
								glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0,0,1));
		m_ViewMatrix = glm::inverse(transform);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}
}