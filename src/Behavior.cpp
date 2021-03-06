#include "Behavior.h"

//Camera* camera = new Camera();

float* Behavior::move(Boid* theBoid, vector <Boid*> *boids)
{
	//compute distance from camera again to determine the state
	float dis= sqrt(pow(theBoid->getX()-camX,2) + pow(theBoid->getY()-camY,2)
				+ pow(theBoid->getZ()-camZ,2));
	if (dis < 100)
		theBoid->setState(false); //Boid not moving
	else
		theBoid->setState(true);

	float* position;
	if (theBoid->getState()==false) //Boid too close to the camera, inactive
	{
		position = theBoid->getPosition(); //don't move
	}
	else
	{
		if(dis < 300 && dis > 100)
		{
			theBoid->setSpeed(0.5*dis/300);
		}
		else
			theBoid->setSpeed(0.5);

		float speed = theBoid->getSpeed();

		float dirX = theBoid->dirX();
		float dirY = theBoid->dirY();
		float dirZ = theBoid->dirZ();
		float distance = theBoid->distance_to_pos(dirX, dirY, dirZ);
		float tmpDirection[3];
		tmpDirection[0] = (dirX / distance) * speed;	//Sets the temporary direction of X (This is equal to, "ammount of X movement / distance between X & Y movement) * velocity")
		tmpDirection[1] = (dirY / distance) * speed;	//Sets the temporary direction of Y (This is equal to, "ammount of Y movement / distance between X & Y movement) * velocity")
		tmpDirection[2] = (dirZ / distance) * speed;	//Sets the temporary direction of Y (This is equal to, "ammount of Y movement / distance between X & Y movement) * velocity")

		float* directionBeforeFlocking = flocking(theBoid, boids, tmpDirection);
		float* goodDirection = wall_bounce(theBoid, directionBeforeFlocking); //check for border collision

		float directionXY = atan2(goodDirection[0], goodDirection[1]);	//Sets the direction based on the new cords
		float directionZ = atan(goodDirection[2]);	//Sets the direction based on the new cords

		if (directionZ < -PI){ directionZ += 2 * PI; } //atan(1)*4 = Pi
		if (directionZ > PI) { directionZ -= 2 * PI; }

		theBoid->setDirectionXY(directionXY);
		theBoid->setDirectionZ(directionZ);

		position = theBoid->getPosition();
		position[0] += theBoid->dirX();
		position[1] += theBoid->dirY();
		position[2] += theBoid->dirZ();
		theBoid->setPosition(position);

	}
	return position;
}

/**
* This function calls the other funcitons (separation, cohesion, alignement to create flocking
*/
float* Behavior::flocking(Boid* theBoid, vector <Boid*> *boids, float* futurePosition){

	float sepX = 0, sepY = 0, sepZ = 0;	//Stores the average X/Y pos's
	float sepCount = 0;		//Stores the number of pos's
	float cohX = 0, cohY = 0, cohZ = 0;
	float cohCount = 0;
	float alignX = 0, alignY = 0, alignZ = 0;	//Stores the average X/Y direction
	float alignCount = 0;			//Stores the number of directions

	float keywordX = 0, keywordY = 0, keywordZ = 0;	//Stores the average X/Y direction
	float keywordCount = 0;			//Stores the number of directions
	/* Here extern keyword user*/
	// mot-cle: eglise
	std::vector<float> keywordUser = { 1, 0, 1, 0, 0, 0 };
	/**/
	if (keywordUser.size() != NULL){
		Boid* boidCamera = new Boid(0, "camera", "url:camera", "this is the camera", true, 0); 
		float positionCamera[3];
		positionCamera[0] = camX;
		positionCamera[1] = camY;
		positionCamera[2] = camZ;
		boidCamera->setPosition(positionCamera);
		
		//boidCamera->setDirectionXY();
		//boidCamera->setDirectionZ();
		boids->push_back(boidCamera);
	}
	for (unsigned int i = 0; i < boids->size(); i++)
	{
		Boid* boidAtI = boids->at(i);
		if (boidAtI->getId() != theBoid->getId() && boidAtI->getState() != false){
			
			float distanceKeyword = theBoid->distanceNDimension(theBoid->getKeywordVector(), boidAtI->getKeywordVector());
			if (distanceKeyword == 0)
			{
				//	float dirXTmp = boidAtI->dirX();
				//	float dirYTmp = boidAtI->dirY();
				//	float dirZTmp = boidAtI->dirZ();
				//	keywordX += boidAtI->getX() + dirXTmp; //Add the boids[i] current X position
				//	keywordY += boidAtI->getY() + dirYTmp; //Add the boids[i] current Y position
				//	keywordZ += boidAtI->getZ() + dirZTmp; //Add the boids[i] current Z position
				//	keywordCount++;
				//}
				//for (int j = theBoid->getKeyword().size() - 1; j > 0; j--){
				//	for (int k = boidAtI->getKeyword().size() - 1; k > 0; k--){
				//		if (theBoid->getKeyword().at(j) == boidAtI->getKeyword().at(k))
				//		{
				//			float dirXTmp = boidAtI->dirX();
				//			float dirYTmp = boidAtI->dirY();
				//			float dirZTmp = boidAtI->dirZ();
				//			keywordX += boidAtI->getX() + dirXTmp; //Add the boids[i] current X position
				//			keywordY += boidAtI->getY() + dirYTmp; //Add the boids[i] current Y position
				//			keywordZ += boidAtI->getZ() + dirZTmp; //Add the boids[i] current Z position
				//			keywordCount++;
				//		}
				//	}
				//}

				float distance = theBoid->getDistance(theBoid, boidAtI);
				if (distance < (RADIUS_SEPARATION))
				{
					sepX += boidAtI->getX();// + boids[i]->dirX();	//Get the average FUTURE positions of the nearby boids, X
					sepY += boidAtI->getY();// + boids[i]->dirY();	//Get the average FUTURE positions of the nearby boids, Y
					sepZ += boidAtI->getZ();// + boids[i]->dirZ();	//Get the average FUTURE positions of the nearby boids, Z
					sepCount++;
				}
				else if (distance < (RADIUS_COHESION))
				{
					float dirXTmp = boidAtI->dirX();
					float dirYTmp = boidAtI->dirY();
					float dirZTmp = boidAtI->dirZ();
					cohX += boidAtI->getX() + dirXTmp; //Add the boids[i] current X position
					cohY += boidAtI->getY() + dirYTmp; //Add the boids[i] current Y position
					cohZ += boidAtI->getZ() + dirZTmp; //Add the boids[i] current Z position
					cohCount++;
					alignX += dirXTmp;	//Add the boids[i] current movement X
					alignY += dirYTmp;	//Add the boids[i] current movement Y
					alignZ += dirZTmp;	//Add the boids[i] current movement Z
					alignCount++;
				}
				futurePosition = cohesion(theBoid, cohX, cohY, cohZ, cohCount, futurePosition);
				futurePosition = separation(theBoid, sepX, sepY, sepZ, sepCount, futurePosition);
				futurePosition = alignment(theBoid, alignX, alignY, alignZ, alignCount, futurePosition);
				sepX = 0, sepY = 0, sepZ = 0;	//Stores the average X/Y pos's
				sepCount = 0;		//Stores the number of pos's
				cohX = 0, cohY = 0, cohZ = 0;
				cohCount = 0;
				alignX = 0, alignY = 0, alignZ = 0;	//Stores the average X/Y direction
				alignCount = 0;			//Stores the number of directions

				//}
				//else{
				//	float distance = theBoid->getDistance(theBoid, boidAtI);
				//	if (distance < 1)
				//	{
				//		sepX += boidAtI->getX();// + boids[i]->dirX();	//Get the average FUTURE positions of the nearby boids, X
				//		sepY += boidAtI->getY();// + boids[i]->dirY();	//Get the average FUTURE positions of the nearby boids, Y
				//		sepZ += boidAtI->getZ();// + boids[i]->dirZ();	//Get the average FUTURE positions of the nearby boids, Z
				//		sepCount++;
				//	}
				//	futurePosition = separation(theBoid, sepX, sepY, sepZ, sepCount, futurePosition);
				//	sepX = 0, sepY = 0, sepZ = 0;	//Stores the average X/Y pos's
				//	sepCount = 0;		//Stores the number of pos's
				//	cohX = 0, cohY = 0, cohZ = 0;
				//	cohCount = 0;
				//	alignX = 0, alignY = 0, alignZ = 0;	//Stores the average X/Y direction
				//	alignCount = 0;			//Stores the number of directions

				//}

			}
		}
	}
	//futurePosition = keyword(theBoid, keywordX, keywordY, keywordZ, keywordCount, futurePosition);
	if (keywordUser.size() != NULL){
		boids->erase(boids->end()-1);
	}
	return futurePosition;
}


/**
* Performs separation
*/
float* Behavior::separation(Boid* theBoid, float sepX, float sepY, float sepZ, float sepCount, float* futurePosition)
{
	if (sepCount > 0)	//Make sure there are some boids nearby before proceding
	{
		float speed = theBoid->getSpeed();
		sepX = theBoid->getX() - (sepX / sepCount);						//Difference between the two positions pos - (averagePos)
		sepY = theBoid->getY() - (sepY / sepCount);						//Difference between the two positions pos - (averagePos)
		sepZ = theBoid->getZ() - (sepZ / sepCount);
		sepX = (sepX / theBoid->distance_to_pos(sepX, sepY, sepZ)) * speed;		//Compute new movement based on the position / distance * velocity
		sepY = (sepY / theBoid->distance_to_pos(sepX, sepY, sepZ)) * speed;		//Compute new movement based on the position / distance * velocity
		sepZ = (sepZ / theBoid->distance_to_pos(sepX, sepY, sepZ)) * speed;		//Compute new movement based on the position / distance * velocity

		sepX = sepX * speed;
		sepY = sepY * speed;
		sepZ = sepZ * speed;

		futurePosition[0] += (sepX - theBoid->dirX()) * (float)SEPARATION;				//Adjust the new movement, Add the difference between sepDirection and current Direction * separation weighting
		futurePosition[1] += (sepY - theBoid->dirY()) * (float)SEPARATION;				//Adjust the new movement, Add the difference between sepDirection and current Direction * separation weighting
		futurePosition[2] += (sepZ - theBoid->dirZ()) * (float)SEPARATION;				//Adjust the new movement, Add the difference between sepDirection and current Direction * separation weighting
	}
	return futurePosition;
}

/**
* Performs cohesion
*/
float* Behavior::cohesion(Boid* theBoid, float cohX, float cohY, float cohZ, float cohCount, float* futurePosition)
{
	if (cohCount > 0)
	{
		float speed = theBoid->getSpeed();
		cohX = (cohX / cohCount) - theBoid->getX();						//Difference in X position between averaged nearby X and current X (avg - curr, means we get the direction to turn towards)
		cohY = (cohY / cohCount) - theBoid->getY();						//Difference in Y position between averaged nearby Y and current Y (avg - curr, means we get the direction to turn towards)
		cohZ = (cohZ / cohCount) - theBoid->getZ();
		cohX = (cohX / theBoid->distance_to_pos(cohX, cohY, cohZ)) * speed;	//Compute the new X movement (Based on the average pos)
		cohY = (cohY / theBoid->distance_to_pos(cohX, cohY, cohZ)) * speed;	//Compute the new Y movement (Based on the average pos)
		cohZ = (cohZ / theBoid->distance_to_pos(cohX, cohY, cohZ)) * speed;
		futurePosition[0] += (cohX - theBoid->dirX()) * (float)COHESION;					//Adjust the new X movement with, difference (average future pos - current movement) * weighting
		futurePosition[1] += (cohY - theBoid->dirY()) * (float)COHESION;					//Adjust the new Y movement with, difference (average future pos - current movement) * weighting
		futurePosition[2] += (cohZ - theBoid->dirZ()) * (float)COHESION;
	}
	return futurePosition;
}

/**
* Performs alignment
*/
float* Behavior::alignment(Boid* theBoid, float alignX, float alignY, float alignZ, float alignCount, float* futurePosition)
{
	if (alignCount > 0)
	{
		alignX = alignX / alignCount;		//Average out the movement
		alignY = alignY / alignCount;		//Average out the movement
		alignZ = alignZ / alignCount;		//Average out the movement
		futurePosition[0] += alignX * (float)ALIGNEMENT;		//Add the averaged out movement * weighting to the new movement direction
		futurePosition[1] += alignY * (float)ALIGNEMENT;		//Add the averaged out movement * weighting to the new movement direction
		futurePosition[2] += alignZ * (float)ALIGNEMENT;
	}
	return futurePosition;
}


float* Behavior::keyword(Boid* theBoid, float keywordX, float keywordY, float keywordZ, float keywordCount, float* futurePosition)
{
	futurePosition = cohesion(theBoid, keywordX, keywordY, keywordZ, keywordCount, futurePosition);
	return futurePosition;
}

/**
* Performs boucing if wall detected
*/
float* Behavior::wall_bounce(Boid* theBoid, float* futurePosition)
{
	if ((theBoid->getX() < 5 && futurePosition[0] <0) || (MAX_X-5< theBoid->getX() && 0 < futurePosition[0]))
	{
		futurePosition[0] = -futurePosition[0];
	}
	if ((theBoid->getY() < 5 && futurePosition[1] <0) || (MAX_Y-5 < theBoid->getY() && 0 < futurePosition[1]))
	{
		futurePosition[1] = -futurePosition[1];
	}
	if ((theBoid->getZ() < 5 && futurePosition[2] < 0) || (MAX_Z-5 < theBoid->getZ() && 0 < futurePosition[2]))
	{
		futurePosition[2] = -futurePosition[2];
	}
	return futurePosition;
}

