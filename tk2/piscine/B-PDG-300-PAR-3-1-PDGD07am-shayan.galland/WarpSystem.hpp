#ifndef _WARP_SYSTEM_HPP
#define _WARP_SYSTEM_HPP

namespace WarpSystem
{
    class QuantumReactor
    {
        private:
            bool _stability;

        public:
            QuantumReactor();
            bool isStable ();
            void setStability(bool stability);
    };

    class Core
    {
        private:
            QuantumReactor* _coreReactor;

        public:
            Core(QuantumReactor* coreReactor);
            QuantumReactor* checkReactor();
    };
}

#endif