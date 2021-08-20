#include "Cube.h"

Cube::Cube() {
	minX = minY = minZ = -1000;
	maxX = maxY = maxZ = 1000;
	calcCoords();
	setColour();
}

Cube::Cube(float minX, float maxX, float minY, float maxY, float minZ, float maxZ) {
	this->minX = minX;
	this->maxX = maxX;
	this->minY = minY;
	this->maxY = maxY;
	this->minZ = minZ;
	this->maxZ = maxZ;
	calcCoords();
	setColour();
}

void Cube::Render() {
	glPushMatrix();

	glColor3f(r, g, b);
	glLineWidth(2);
	drawEdge(0, 1);
	drawEdge(1, 2);
	drawEdge(2, 3);
	drawEdge(3, 0);
	drawEdge(4, 5);
	drawEdge(5, 6);
	drawEdge(6, 7);
	drawEdge(7, 4);
	drawEdge(4, 0);
	drawEdge(1, 5);
	drawEdge(2, 6);
	drawEdge(3, 7);
	// Draw faces
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(r, g, b, a);
	drawFace(0, 4, 5, 1);
	drawFace(3, 7, 4, 0);
	drawFace(2, 6, 7, 3);
	drawFace(1, 5, 6, 2);
	drawFace(3, 0, 1, 2);
	drawFace(4, 7, 6, 5);
	glDisable(GL_BLEND);
	glPopMatrix();



}



void Cube::drawFace(int i0, int i1, int i2, int i3)
{
	glBegin(GL_QUADS);
	glVertex3f(vertices[i0].x, vertices[i0].y, vertices[i0].z);
	glVertex3f(vertices[i1].x, vertices[i1].y, vertices[i1].z);
	glVertex3f(vertices[i2].x, vertices[i2].y, vertices[i2].z);
	glVertex3f(vertices[i3].x, vertices[i3].y, vertices[i3].z);
	glEnd();
}

void Cube::drawEdge(int i0, int i1)
{
	glBegin(GL_LINES);
	glVertex3f(vertices[i0].x, vertices[i0].y, vertices[i0].z);
	glVertex3f(vertices[i1].x, vertices[i1].y, vertices[i1].z);
	glEnd();
}

void Cube::calcCoords() {
	vertices[0].set(minX, maxY, maxZ);
	vertices[1].set(maxX, maxY, maxZ);
	vertices[2].set(maxX, maxY, minZ);
	vertices[3].set(minX, maxY, minZ);
	vertices[4].set(minX, minY, maxZ);
	vertices[5].set(maxX, minY, maxZ);
	vertices[6].set(maxX, minY, minZ);
	vertices[7].set(minX, minY, minZ);
}

void Cube::setColour(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

