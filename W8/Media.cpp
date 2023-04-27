

#include "Media.h"

namespace sdds{
    std::ostream& operator<<(std::ostream& os, const Media& media){
        return media.play(os);
    }
    std::istream& operator>>(std::istream& is, Media& media){
        media.load(is);
        return is;
    }
}