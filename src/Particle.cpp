
#include "Particle.h"

namespace traer { namespace physics {

    Particle::Particle( const float &m )
    {
        mass = m;
        age = 0;
        fixed = false;
		locked = false;
        position.set(0,0,0);
        velocity.set(0,0,0);
        force.set(0,0,0);
    }

    void Particle::reset()
    {
        mass = 1.0f;
        age = 0;
        fixed = false;
		locked = false;
        position.set(0,0,0);
        velocity.set(0,0,0);
        force.set(0,0,0);
    }

} } // namespace traer::physics