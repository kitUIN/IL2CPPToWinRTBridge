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
    };
    public ref class BridgeMessage sealed
    {
    private:
        MessageType m_type;
        Platform::Object^ m_data;
        Windows::Foundation::DateTime m_sendTime;
    public:
        BridgeMessage(MessageType _type, Platform::Object^ _data)
        {
            m_type = _type;
            m_data = _data;
            SYSTEMTIME st;
            GetSystemTime(&st);
            FILETIME ft;
            SystemTimeToFileTime(&st, &ft);
            ULARGE_INTEGER uli;
            uli.LowPart = ft.dwLowDateTime;
            uli.HighPart = ft.dwHighDateTime;
            m_sendTime.UniversalTime = uli.QuadPart;
        }
        BridgeMessage(MessageType _type, Platform::Object^ _data, Windows::Foundation::DateTime dt)
        {
            m_type = _type;
            m_data = _data;
            m_sendTime = dt;
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
        /// <summary>
        /// ����ʱ��
        /// </summary>
        property Windows::Foundation::DateTime SendTime
        {
            Windows::Foundation::DateTime get() { return m_sendTime; }
        }
        
        Platform::String^ ToString() override
        {
            return "[BridgeMessage(MessageType=" + m_type.ToString() + ",Data=" + m_data->ToString() + ")]";
        }
    };
}