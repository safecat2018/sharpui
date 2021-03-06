// 华勤科技版权所有 2010-2011
// 
// 文件名：CaptionBar.h
// 功  能：实现Windows标准的标题。
// 
// 作  者：汪荣
// 时  间：2010-07-02
// 
// ============================================================================

# ifndef _UICAPTIONBAR_H_
# define _UICAPTIONBAR_H_

#include <sui/StackLayout.h>
#include <sui/Button.h>
#include <sui/Label.h>

namespace ui
{

class SHARPUI_API CaptionBar : public ui::StackLayout
{
public:

    CaptionBar();
    virtual ~CaptionBar();

    DeclareTypeofInfo(CaptionBar, StackLayout)

    /// <summary>
    ///     隐藏系统最小化按钮
    /// </summary>
    /// <param name="value">true:隐藏；false；显示</param>
    /// <returns>无</returns>
    void HideMinBox(bool value);

    /// <summary>
    ///     隐藏系统最大化按钮
    /// </summary>
    /// <param name="value">true:隐藏；false；显示</param>
    /// <returns>无</returns>
    void HideMaxBox(bool value);

    /// <summary>
    ///     隐藏系统关闭按钮
    /// </summary>
    /// <param name="value">true:隐藏；false；显示</param>
    /// <returns>无</returns>
    void HideCloseBox(bool value);

    bool IsRender() const;

protected:

    void OnInitialized();

    void OnRender(suic::DrawingContext * drawing);

    void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnMouseLeftButtonDbclk(suic::MouseEventArg& e);
    void OnMouseLeftButtonUp(suic::MouseEventArg& e);
    void OnMouseEnter(suic::MouseEventArg& e);
    void OnMouseMove(suic::MouseEventArg& e);
    void OnMouseLeave(suic::MouseEventArg& e);

protected:

    // 标题文本
    ui::LabelPtr _title;
    // 最大化按钮
    suic::ElementPtr _maxBtn;

};

inline bool CaptionBar::IsRender() const
{
    return true;
}

}

# endif
