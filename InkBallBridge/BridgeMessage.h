#pragma once

namespace InkBallBridge
{
    public enum class MessageType 
    { 
        /// <summary>
        /// ��ǰ�ؿ�
        /// </summary>
        CurrentLevel,
        /// <summary>
        /// ���йؿ�
        /// </summary>
        AllLevel,
        /// <summary>
        /// ��ǰ����
        /// </summary>
        CurrentScore,
        /// <summary>
        /// ��Ϸ�Ƿ���ͣ
        /// </summary>
        Pause,
        /// <summary>
        /// ����
        /// </summary>
        Theme,
        /// <summary>
        /// ��������
        /// </summary>
        Remake,
        /// <summary>
        /// ����
        /// </summary>
        Get,
        /// <summary>
        /// ������
        /// </summary>
        BallCounts,
        /// <summary>
        /// ����Ϣ
        /// </summary>
        Ball,
        /// <summary>
        /// ����Ϸ�������
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
        /// ����
        /// </summary>
        property BallType Type
        {
            BallType get() { return m_type; }
        }
        /// <summary>
        /// ����
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
        /// ����
        /// </summary>
        property MessageType Type
        {
            MessageType get() { return m_type; }
        }
        /// <summary>
        /// ����
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