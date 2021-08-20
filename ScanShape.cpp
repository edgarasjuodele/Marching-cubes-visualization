#include "ScanShape.h"

ScanShape::ScanShape() {
	minX = minY = minZ = -1000;
	maxX = maxY = maxZ = 1000;
	part = 0;
	calcCoords();
	setColour();
}

ScanShape::ScanShape(float minX, float maxX, float minY, float maxY, float minZ, float maxZ) {
	this->minX = minX;
	this->maxX = maxX;
	this->minY = minY;
	this->maxY = maxY;
	this->minZ = minZ;
	this->maxZ = maxZ;
	calcCoords();
	setColour();
}

void ScanShape::Render(int part, bool mode, float angle) {
	
	glPushMatrix();
	
	glRotatef(angle, 0, 1, 0);

	if (mode) {
		glColor3f(0, 1, 0);
		glLineWidth(2);
		if (part >= 1) {
			drawEdge(18, 13);
			drawEdge(13, 14);
			drawEdge(14, 18);
		}
		if (part >= 2) {
			glTranslatef(-4.0f, 0, 0);
			drawEdge(14, 19);
			drawEdge(19, 13);
			drawEdge(13, 17);
			drawEdge(17, 19);
			drawEdge(13, 14);
		}
		if (part >= 3) {
			glTranslatef(-4.0f, 0, 0);
			drawEdge(18, 19);
			drawEdge(19, 17);
			drawEdge(17, 18);
		}
		if (part >= 4) {
			glTranslatef(8.0f, -4.0f, 0);
			drawEdge(9, 15);
			drawEdge(15, 13);
			drawEdge(9, 13);
			drawEdge(15, 18);
			drawEdge(13, 18);
		}
		if (part >= 5) {
			glTranslatef(-4.0f, 0, 0);
			drawEdge(16, 13);
			drawEdge(13, 17);
			drawEdge(17, 16);
			drawEdge(16, 9);
			drawEdge(13, 9);
		}
		if (part >= 6) {
			glTranslatef(-4.0f, 0, 0);
			drawEdge(16, 17);
			drawEdge(17, 15);
			drawEdge(15, 16);
			drawEdge(17, 18);
			drawEdge(15, 18);
		}
		if (part >= 7) {
			glTranslatef(8.0f, -4.0f, 0);
			drawEdge(15, 9);
			drawEdge(9, 14);
			drawEdge(14, 15);
		}
		if (part >= 8) {
			glTranslatef(-4.0f, 0, 0);
			drawEdge(14, 9);
			drawEdge(9, 16);
			drawEdge(16, 14);
			drawEdge(14, 19);
			drawEdge(19, 16);
		}
		if (part >= 9) {
			glTranslatef(-4.0f, 0, 0);
			drawEdge(19, 15);
			drawEdge(15, 16);
			drawEdge(16, 19);
		}
		if (part >= 10) {
			glTranslatef(8.0f, 8.0f, -4.0);
			drawEdge(10, 11);
			drawEdge(11, 18);
			drawEdge(18, 14);
			drawEdge(14, 10);
			drawEdge(10, 18);
		}
		if (part >= 11) {
			glTranslatef(-4.0f, 0, 0);
			drawEdge(10, 12);
			drawEdge(12, 14);
			drawEdge(14, 19);
			drawEdge(19, 12);
			drawEdge(14, 10);
		}
		if (part >= 12) {
			glTranslatef(-4.0f, 0, 0);
			drawEdge(11, 12);
			drawEdge(12, 18);
			drawEdge(18, 11);
			drawEdge(18, 19);
			drawEdge(19, 12);
		}
		if (part >= 13) {
			glTranslatef(8.0f, -4.0f, 0);
			drawEdge(8, 15);
			drawEdge(15, 11);
			drawEdge(11, 8);
			drawEdge(15, 18);
			drawEdge(11, 18);
		}
		if (part >= 14) {
			glTranslatef(-4.0f, 0, 0);
		}
		if (part >= 15) {
			glTranslatef(-4.0f, 0, 0);
			drawEdge(8, 15);
			drawEdge(15, 11);
			drawEdge(11, 8);
			drawEdge(15, 18);
			drawEdge(11, 18);
		}
		if (part >= 16) {
			glTranslatef(8.0f, -4.0f, 0);
			drawEdge(10, 14);
			drawEdge(14, 8);
			drawEdge(8, 10);
			drawEdge(8, 15);
			drawEdge(15, 14);
		}
		if (part >= 17) {
			glTranslatef(-4.0f, 0, 0);
			drawEdge(10, 12);
			drawEdge(12, 14);
			drawEdge(14, 10);
			drawEdge(14, 19);
			drawEdge(19, 12);
		}
		if (part >= 18) {
			glTranslatef(-4.0f, 0, 0);
			drawEdge(8, 15);
			drawEdge(15, 19);
			drawEdge(19, 8);
			drawEdge(15, 19);
			drawEdge(19, 12);
		}
		if (part >= 19) {
			glTranslatef(8.0f, 8.0f, -4.0);
			drawEdge(10, 13);
			drawEdge(13, 11);
			drawEdge(11, 10);
		}
		if (part >= 20) {
			glTranslatef(-4.0f, 0, 0);
			drawEdge(12, 10);
			drawEdge(10, 13);
			drawEdge(13, 12);
			drawEdge(12, 17);
			drawEdge(17, 13);
		}
		if (part >= 21) {
			glTranslatef(-4.0f, 0, 0);
			drawEdge(12, 11);
			drawEdge(11, 17);
			drawEdge(17, 12);
		}
		if (part >= 22) {
			glTranslatef(8.0f, -4.0f, 0);
			drawEdge(9, 8);
			drawEdge(8, 11);
			drawEdge(11, 9);
			drawEdge(9, 13);
			drawEdge(13, 11);
		}
		if (part >= 23) {
			glTranslatef(-4.0f, 0, 0);
			drawEdge(9, 16);
			drawEdge(16, 17);
			drawEdge(17, 9);
			drawEdge(17, 13);
			drawEdge(13, 9);
		}
		if (part >= 24) {
			glTranslatef(-4.0f, 0, 0);
			drawEdge(16, 17);
			drawEdge(17, 8);
			drawEdge(8, 16);
			drawEdge(17, 11);
			drawEdge(11, 8);
		}
		if (part >= 25) {
			glTranslatef(8.0f, -4.0f, 0);
			drawEdge(9, 8);
			drawEdge(8, 10);
			drawEdge(10, 9);
		}
		if (part >= 26) {
			glTranslatef(-4.0f, 0, 0);
			drawEdge(9, 10);
			drawEdge(10, 16);
			drawEdge(16, 9);
			drawEdge(16, 12);
			drawEdge(10, 12);
		}
		if (part >= 27) {
			glTranslatef(-4.0f, 0, 0);
			drawEdge(8, 12);
			drawEdge(12, 16);
			drawEdge(16, 8);
		}
	}

	if (!mode) {
		glColor3f(0.8, 0, 0.2);
		glLineWidth(3);
		if (part >= 1) {
			drawEdge(18, 13);
			drawEdge(13, 14);
			drawEdge(14, 18);
			glColor4f(r, g, b, a);
			drawPart(18, 13, 14);
		}
		if (part >= 2) {
			glTranslatef(-4.0f, 0, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(14, 19);
			drawEdge(19, 13);
			drawEdge(13, 17);
			drawEdge(17, 19);
			drawEdge(13, 14);
			glColor4f(r, g, b, a);
			drawPart(14, 19, 13);
			drawPart(13, 17, 19);

		}
		if (part >= 3) {
			glTranslatef(-4.0f, 0, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(18, 19);
			drawEdge(19, 17);
			drawEdge(17, 18);
			glColor4f(r, g, b, a);
			drawPart(19, 18, 17);
		}
		if (part >= 4) {
			glTranslatef(8.0f, -4.0f, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(9, 15);
			drawEdge(15, 13);
			drawEdge(9, 13);
			drawEdge(15, 18);
			drawEdge(13, 18);
			glColor4f(r, g, b, a);
			drawPart(9, 15, 13);
			drawPart(13, 15, 18);

		}
		if (part >= 5) {
			glTranslatef(-4.0f, 0, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(16, 13);
			drawEdge(13, 17);
			drawEdge(17, 16);
			drawEdge(16, 9);
			drawEdge(13, 9);
			glColor4f(r, g, b, a);
			drawPart(16, 13, 17);
			drawPart(16, 13, 9);

		}
		if (part >= 6) {
			glTranslatef(-4.0f, 0, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(16, 17);
			drawEdge(17, 15);
			drawEdge(15, 16);
			drawEdge(17, 18);
			drawEdge(15, 18);
			glColor4f(r, g, b, a);
			drawPart(16, 17, 15);
			drawPart(15, 17, 18);

		}
		if (part >= 7) {
			glTranslatef(8.0f, -4.0f, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(15, 9);
			drawEdge(9, 14);
			drawEdge(14, 15);
			glColor4f(r, g, b, a);
			drawPart(15, 9, 14);

		}
		if (part >= 8) {
			glTranslatef(-4.0f, 0, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(14, 9);
			drawEdge(9, 16);
			drawEdge(16, 14);
			drawEdge(14, 19);
			drawEdge(19, 16);
			glColor4f(r, g, b, a);
			drawPart(14, 9, 16);
			drawPart(16, 14, 19);
		}
		if (part >= 9) {
			glTranslatef(-4.0f, 0, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(19, 15);
			drawEdge(15, 16);
			drawEdge(16, 19);
			glColor4f(r, g, b, a);
			drawPart(19, 15, 16);
		}
		if (part >= 10) {
			glTranslatef(8.0f, 8.0f, -4.0);
			
			drawEdge(10, 11);
			drawEdge(11, 18);
			drawEdge(18, 14);
			drawEdge(14, 10);
			drawEdge(10, 18);
			glColor4f(r, g, b, a);
			drawPart(10, 11, 18);
			drawPart(18, 14, 10);
		}
		if (part >= 11) {
			glTranslatef(-4.0f, 0, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(10, 12);
			drawEdge(12, 14);
			drawEdge(14, 19);
			drawEdge(19, 12);
			drawEdge(14, 10);
			glColor4f(r, g, b, a);
			drawPart(10, 12, 14);
			drawPart(14, 12, 19);
		}
		if (part >= 12) {
			glTranslatef(-4.0f, 0, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(11, 12);
			drawEdge(12, 18);
			drawEdge(18, 11);
			drawEdge(18, 19);
			drawEdge(19, 12);
			glColor4f(r, g, b, a);
			drawPart(11, 12, 18);
			drawPart(18, 19, 12);
		}
		if (part >= 13) {
			glTranslatef(8.0f, -4.0f, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(8, 15);
			drawEdge(15, 11);
			drawEdge(11, 8);
			drawEdge(15, 18);
			drawEdge(11, 18);
			glColor4f(r, g, b, a);
			drawPart(8, 15, 11);
			drawPart(11, 15, 18);
		}
		if (part >= 14) {
			glTranslatef(-4.0f, 0, 0);
		}
		if (part >= 15) {
			glTranslatef(-4.0f, 0, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(8, 15);
			drawEdge(15, 11);
			drawEdge(11, 8);
			drawEdge(15, 18);
			drawEdge(11, 18);
			glColor4f(r, g, b, a);
			drawPart(8, 15, 11);
			drawPart(11, 15, 18);
		}
		if (part >= 16) {
			glTranslatef(8.0f, -4.0f, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(10, 14);
			drawEdge(14, 8);
			drawEdge(8, 10);
			drawEdge(8, 15);
			drawEdge(15, 14);
			glColor4f(r, g, b, a);
			drawPart(10, 14, 8);
			drawPart(8, 15, 14);
		}
		if (part >= 17) {
			glTranslatef(-4.0f, 0, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(10, 12);
			drawEdge(12, 14);
			drawEdge(14, 10);
			drawEdge(14, 19);
			drawEdge(19, 12);
			glColor4f(r, g, b, a);
			drawPart(10, 12, 14);
			drawPart(14, 12, 19);
		}
		if (part >= 18) {
			glTranslatef(-4.0f, 0, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(8, 15);
			drawEdge(15, 19);
			drawEdge(19, 8);
			drawEdge(15, 19);
			drawEdge(19, 12);
			glColor4f(r, g, b, a);
			drawPart(8, 15, 19);
			drawPart(19, 12, 8);
		}
		if (part >= 19) {
			glTranslatef(8.0f, 8.0f, -4.0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(10, 13);
			drawEdge(13, 11);
			drawEdge(11, 10);
			glColor4f(r, g, b, a);
			drawPart(10, 13, 11);
		}
		if (part >= 20) {
			glTranslatef(-4.0f, 0, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(12, 10);
			drawEdge(10, 13);
			drawEdge(13, 12);
			drawEdge(12, 17);
			drawEdge(17, 13);
			glColor4f(r, g, b, a);
			drawPart(12, 10, 13);
			drawPart(13, 17, 10);
		}
		if (part >= 21) {
			glTranslatef(-4.0f, 0, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(12, 11);
			drawEdge(11, 17);
			drawEdge(17, 12);
			glColor4f(r, g, b, a);
			drawPart(12, 11, 17);
		}
		if (part >= 22) {
			glTranslatef(8.0f, -4.0f, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(9, 8);
			drawEdge(8, 11);
			drawEdge(11, 9);
			drawEdge(9, 13);
			drawEdge(13, 11);
			glColor4f(r, g, b, a);
			drawPart(9, 8, 11);
			drawPart(11, 13, 9);
		}
		if (part >= 23) {
			glTranslatef(-4.0f, 0, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(9, 16);
			drawEdge(16, 17);
			drawEdge(17, 9);
			drawEdge(17, 13);
			drawEdge(13, 9);
			glColor4f(r, g, b, a);
			drawPart(9, 16, 17);
			drawPart(17, 9, 13);
		}
		if (part >= 24) {
			glTranslatef(-4.0f, 0, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(16, 17);
			drawEdge(17, 8);
			drawEdge(8, 16);
			drawEdge(17, 11);
			drawEdge(11, 8);
			glColor4f(r, g, b, a);
			drawPart(16, 17, 8);
			drawPart(8, 17, 11);
		}
		if (part >= 25) {
			glTranslatef(8.0f, -4.0f, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(9, 8);
			drawEdge(8, 10);
			drawEdge(10, 9);
			glColor4f(r, g, b, a);
			drawPart(9, 8, 10);

		}
		if (part >= 26) {
			glTranslatef(-4.0f, 0, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(9, 10);
			drawEdge(10, 16);
			drawEdge(16, 9);
			drawEdge(16, 12);
			drawEdge(10, 12);
			glColor4f(r, g, b, a);
			drawPart(9, 10, 16);
			drawPart(16, 12, 10);
		}
		if (part >= 27) {
			glTranslatef(-4.0f, 0, 0);
			glColor3f(0.8, 0, 0.2);
			drawEdge(8, 12);
			drawEdge(12, 16);
			drawEdge(16, 8);
			glColor4f(r, g, b, a);
			drawPart(8, 12, 16);
		}
	}
	glPopMatrix();

}



void ScanShape::drawPart(int i0, int i1, int i2)
{
	glBegin(GL_TRIANGLES);
	glVertex3f(vertices[i0].x, vertices[i0].y, vertices[i0].z);
	glVertex3f(vertices[i1].x, vertices[i1].y, vertices[i1].z);
	glVertex3f(vertices[i2].x, vertices[i2].y, vertices[i2].z);
	glEnd();
}

void ScanShape::drawEdge(int i0, int i1)
{
	glBegin(GL_LINES);
	glVertex3f(vertices[i0].x, vertices[i0].y, vertices[i0].z);
	glVertex3f(vertices[i1].x, vertices[i1].y, vertices[i1].z);
	glEnd();
}

void ScanShape::calcCoords() {
	vertices[0].set(minX, maxY, maxZ); //v5
	vertices[1].set(maxX, maxY, maxZ); //v6
	vertices[2].set(maxX, maxY, minZ); //v7
	vertices[3].set(minX, maxY, minZ); //v4
	vertices[4].set(minX, minY, maxZ); //v1
	vertices[5].set(maxX, minY, maxZ); //v2
	vertices[6].set(maxX, minY, minZ); //v3
	vertices[7].set(minX, minY, minZ); //v0
	// im stupid
	vertices[8].set(0, maxY, maxZ); //5
	vertices[9].set(minX, maxY, 0); //4
	vertices[10].set(minX, 0, maxZ); //10
	vertices[11].set(0, minY, maxZ); //1
	vertices[12].set(maxX, 0, maxZ); //12
	vertices[13].set(minX, minY, 0); //0
	vertices[14].set(minX, 0, minZ); //8
	vertices[15].set(0, maxY, minZ); //7
	vertices[16].set(maxX, maxY, 0); //6
	vertices[17].set(maxX, minY, 0); //2
	vertices[18].set(0, minY, minZ); //3
	vertices[19].set(maxX, 0, minZ); //14

}

void ScanShape::setColour(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}
