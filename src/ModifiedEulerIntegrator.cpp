#include "cinder/Vector.h"
#include "ModifiedEulerIntegrator.h"

namespace traer { namespace physics {

	ModifiedEulerIntegrator::ModifiedEulerIntegrator( ParticleSystem *system )
	{
		s = system;
	}
	
	void ModifiedEulerIntegrator::step( const float &t )
	{
		s->clearForces();
		s->applyForces();
		
		const float halftt = 0.5f*t*t;
		
		for ( int i = 0; i < s->numberOfParticles(); i++ )
		{
			Particle* p = s->getParticle( i );
			if ( p->isFree() )
			{
                const ci::Vec3f force = *(p->getForce());
                const float mass = p->getMass();
                const ci::Vec3f a = force / mass;
				
                ci::Vec3f position = *(p->getPosition());
                ci::Vec3f velocity = *(p->getVelocity());
                position += velocity/t;
                position += a * halftt;
                velocity += a / t;
			}
		}
	}

} } // namespace traer::physics