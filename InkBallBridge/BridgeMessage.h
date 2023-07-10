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
        /// ���
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