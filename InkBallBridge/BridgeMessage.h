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
        /// 球数量
        /// </summary>
        BallCounts,
        /// <summary>
        /// 球信息
        /// </summary>
        Ball,
        /// <summary>
        /// 往游戏里添加球
        /// </summary>
        BallLoad,
    };
    public enum class BallType
    {
        White,
        Blue,
        Green,
        Orange,
        Yellow,
    };
    public ref class BallInfo sealed
    {
    private:
        int m_index;
        BallType m_type;
    public:
        BallInfo(int _index, BallType _type)
        {
            m_index = _index;
            m_type = _type; 
        }
        /// <summary>
        /// 类型
        /// </summary>
        property BallType Type
        {
            BallType get() { return m_type; }
        }
        /// <summary>
        /// 索引
        /// </summary>
        property int Index
        {
            int get() { return m_index; }
        }
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