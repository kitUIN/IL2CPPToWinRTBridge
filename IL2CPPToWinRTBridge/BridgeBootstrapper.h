#pragma once

namespace IL2CPPToWinRTBridge
{
    public interface class IWinRTBridge
    {
        public:
            void Connect(Platform::String^ arg);
    };
    public interface class IIL2CPPBridge
    {
        public:
            void Connect(Platform::String^ arg);
    };
    
    public ref class BridgeBootstrapper sealed
    {
        public:
            static IWinRTBridge^ GetWinRTBridge()
            {
                return m_WinRTBridge;
            }

            static void SetWinRTBridge(IWinRTBridge^ WinRTBridge)
            {
                m_WinRTBridge = WinRTBridge;
            }

            static IIL2CPPBridge^ GetIL2CPPBridge()
            {
                return m_IL2CPPBridge;
            }

            static void SetIL2CPPBridge(IIL2CPPBridge^ il2cppBridge)
            {
                m_IL2CPPBridge = il2cppBridge;
            }

        private:
            static IWinRTBridge^ m_WinRTBridge;
            static IIL2CPPBridge^ m_IL2CPPBridge;

            BridgeBootstrapper();
     };

    IWinRTBridge^ BridgeBootstrapper::m_WinRTBridge;
    IIL2CPPBridge^ BridgeBootstrapper::m_IL2CPPBridge;
}