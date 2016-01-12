#ifndef __TOUCH_SCREEN_API_H__
#define __TOUCH_SCREEN_API_H__

#include <vector>
#include <string>

using namespace ::std;

class ScreenMatrix {
public:
    virtual string operator()(const std::vector<int>& data) = 0;
    virtual ~ScreenMatrix() {}
};

ScreenMatrix* createScreenMatrix();

#endif /* __TOUCH_SCREEN_API_H__ */
