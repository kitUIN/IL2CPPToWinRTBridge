#pragma once
#include <BridgeMessage.h>

namespace InkBallBridge
{
    /// <summary>
    /// 仅WinRT程序中继承
    /// </summary>
    public interface class IWinRTBridge
    {
    public:
        void Connect(BridgeMessage^ message);
    };
    /// <summary>
    /// 仅Unity(Il2Cpp)程序中继承
    /// </summary>
    public interface class IIL2CPPBridge
    {
    public:
        void Connect(BridgeMessage^ message);
    };
    /// <summary>
    /// 通讯桥
    /// </summary>
    public ref class Bridge sealed
    {
    public:
        static IWinRTBridge^ GetWinRTBridge()
        {
            return m_WinRTBridge;
        }
        /// <summary>
        /// 仅WinRT程序中设置
        /// </summary>
        static void SetWinRTBridge(IWinRTBridge^ WinRTBridge)
        {
            m_WinRTBridge = WinRTBridge;
        }
        static IIL2CPPBridge^ GetIL2CPPBridge()
        {
            return m_IL2CPPBridge;
        }

        /// <summary>
        /// 仅Unity(Il2Cpp)程序中设置
        /// </summary>
        static void SetIL2CPPBridge(IIL2CPPBridge^ il2cppBridge)
        {
            m_IL2CPPBridge = il2cppBridge;
        }

    private:
        static IWinRTBridge^ m_WinRTBridge;
        static IIL2CPPBridge^ m_IL2CPPBridge;

        Bridge();
    };

    IWinRTBridge^ Bridge::m_WinRTBridge;
    IIL2CPPBridge^ Bridge::m_IL2CPPBridge;
}