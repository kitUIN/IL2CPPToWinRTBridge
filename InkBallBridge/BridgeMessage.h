#pragma once

namespace InkBallBridge
{
    public enum class MessageType 
    { 
        /// <summary>
        /// 当前关卡
        /// </summary>
        CurrentLevel,
        /// <summary>
        /// 所有关卡
        /// </summary>
        AllLevel,
        /// <summary>
        /// 当前分数
        /// </summary>
        CurrentScore,
        /// <summary>
        /// 游戏是否暂停
        /// </summary>
        Pause,
        /// <summary>
        /// 主题
        /// </summary>
        Theme,
        /// <summary>
        /// 重启本关
        /// </summary>
        Remake,
        /// <summary>
        /// 请求
        /// </summary>
        Get,
        /// <summary>
        /// 球仓
        /// </summary>
        BallCounts,

    };
    public ref class BridgeMessage sealed
    {
    private:
        MessageType m_type;
        Platform::Object^ m_data;
    public:
        BridgeMessage(MessageType _type, Platform::Object^ _data)
        {
            m_type = _type;
            m_data = _data;
        }
        /// <summary>
        /// 类型
        /// </summary>
        property MessageType Type
        {
            MessageType get() { return m_type; }
        }
        /// <summary>
        /// 数据
        /// </summary>
        property Platform::Object^ Data
        {
            Platform::Object^ get() { return m_data; }
        }
        
        Platform::String^ ToString() override
        {
            return "[BridgeMessage(MessageType=" + m_type.ToString() + ",Data=" + m_data->ToString() + ")]";
        }
    };
}