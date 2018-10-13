#include "object.h"

void shiftMapObjects(Object* objects, ObjectPoint shift, u32 count)
{
    for (u32 index = 0; index < count; index++)
    {
        objects[index].position.x += shift.x;
        objects[index].position.y += shift.y;
    }
}