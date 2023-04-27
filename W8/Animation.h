
#ifndef SDDS_ANIMATION_H__
#define SDDS_ANIMATION_H__

#include "Video.h"

namespace sdds {
    class Animation : public Video {
    private:
        int m_dimension{};
    public:
        Animation();
        Animation(const Animation&) = delete;
        Animation& operator=(const Animation&) = delete;
        Animation(int length, int dimension);
        void load(std::istream& is) override;
        std::ostream& play(std::ostream& os) const override;
    };
}

#endif // !SDDS_ANIMATION_H__