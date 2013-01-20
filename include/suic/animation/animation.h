// ���ڿƼ���Ȩ���� 2010-2012
// 
// �ļ�����animation.h
// ��  �ܣ����嶯�����࣬�κζ������������̳С�
// 
// ��  �ߣ�����
// ʱ  �䣺2012-02-01
// 
// ============================================================================

# ifndef _UIANIMATION_H_
# define _UIANIMATION_H_

#include <suic/animation/timeline.h>
#include <suic/framework/uiframeworkelement.h>
#include <suic/graphics/UIDrawing.h>

namespace suic
{

typedef delegate<void(FrameworkElement*)> StartAnimationHandler;
typedef delegate<void(FrameworkElement*)> FinishAnimationHandler;

/// <summary>
/// �������ƶ���
/// </summary>
class SUICORE_API AnimateAction
{
public:

    // ����ƫ��
    Point offset;

    // ��ת�Ƕ�
    double radio;

    // ͸����
    double alpha;

    // ���Ⱥ͸߶����ű���
    double widRadio;
    double heiRadio;

    // �û���ͼ���Զ��崦��
    ImagePtr image;

    // ʹ��image����
    bool useimage;

    AnimateAction();
};

class SUICORE_API Animation : public Timeline
{
public:

    StartAnimationHandler StartAnimation;
    FinishAnimationHandler FinishAnimation;

    Animation();
    virtual ~Animation();

    bool IsRunning() const;
    bool IsPause() const;

    bool IsEndOf() const;

    /// <summary>
    ///     ��ȡ��һ֡�����ļ��ʱ��
    /// </summary>
    /// <remarks>
    ///     ÿ�ֶ������Ͷ�Ӧ�ø�����Ӧ���㷨���㶯��֡���
    /// </remarks>
    /// <returns>��һ֡���ʱ��</returns>
    virtual double GetInterval();

    /// <summary>
    ///     ����һ֡����
    /// </summary>
    /// <remarks>
    ///     ���ô˷������㵱ǰʱ���Ķ���֡����㶯��Ԫ�ص�״̬
    /// </remarks>
    /// <param name="pElem">Ŀ��Ԫ��</param>
    /// <returns>��</returns>
    virtual void OnMeasure(FrameworkElement* pElem);

    /// <summary>
    ///     ���㵱ǰ����֡
    /// </summary>
    /// <remarks>
    ///     �˷�����Ϊ���Զ������ᱻ����
    /// </remarks>
    /// <param name="pImage">�ؼ�֡����</param>
    /// <returns>��</returns>
    virtual void OnFrame(FrameworkElement* pElem, AnimateAction& act);

    /// <summary>
    ///     ������ʼʱ�ص�
    /// </summary>
    /// <param name="pElem">Ŀ��Ԫ��</param>
    /// <returns>��</returns>
    virtual void OnStart(FrameworkElement* pElem);

    /// <summary>
    ///     ��������ʱ�ص�
    /// </summary>
    /// <param name="pElem">Ŀ��Ԫ��</param>
    /// <returns>��</returns>
    virtual void OnFinish(suic::FrameworkElement* pElem);

    /// <summary>
    ///     ������ͣʱ�ص�
    /// </summary>
    /// <returns>��</returns>
    virtual void OnPause();

    /// <summary>
    ///     �������²���ʱ�ص�
    /// </summary>
    /// <returns>��</returns>
    virtual void OnResume();

protected:

    // ����״̬
    // 0��ֹͣ��1�������У�2����ͣ
    int _state;

    // �����Ƿ�������ɾ��嶯������
    bool _isEndOf;
};

typedef shared<Animation> AnimationPtr;

};

# endif