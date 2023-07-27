#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

class IMonitorDisplay {
    public:
        IMonitorDisplay() {};
        virtual ~IMonitorDisplay() {};
        virtual bool start() = 0;
};

#endif