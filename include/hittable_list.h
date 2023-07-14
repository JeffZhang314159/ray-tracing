#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST

#include <memory>
#include <vector>

#include "hittable.h"

class HittableList : public Hittable {
    std::vector<std::shared_ptr<Hittable>> objects;

    public:
        public:
        HittableList() {}
        HittableList(std::shared_ptr<Hittable> object) { add(object); }

        void clear() { objects.clear(); }
        void add(std::shared_ptr<Hittable> object) { objects.push_back(object); }

        virtual bool hit(const Ray& r, double t_min, double t_max, HitInfo& rec) const override;
};

bool HittableList::hit(const Ray& r, double t_min, double t_max, HitInfo& hitInfo) const {
    double min_t = t_max;
    bool hit = false;
    HitInfo tempInfo;

    for (const auto& object : objects) {
        if (object->hit(r, t_min, t_max, tempInfo)) {
            if (tempInfo.t < min_t) {
                hit = true;
                min_t = tempInfo.t;
                hitInfo = tempInfo;
            }
        }
    }

    return hit;
}

#endif