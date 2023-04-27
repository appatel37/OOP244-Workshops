
#ifndef SDDS_VRVIDEO_H__
#define SDDS_VRVIDEO_H__

#include "Video.h"

namespace sdds {
    class VRVideo : public Video {
    private:
        char* m_equipment{};
    public:
        VRVideo();
        
        VRVideo(const VRVideo&) = delete;
        
        VRVideo& operator=(const VRVideo&) = delete;
        
        VRVideo(int length, const char* equipment);
        ~VRVideo();
        void load(std::istream& is) override;
        std::ostream& play(std::ostream& os) const override;
    };
}

#endif // !SDDS_VRVIDEO_H__