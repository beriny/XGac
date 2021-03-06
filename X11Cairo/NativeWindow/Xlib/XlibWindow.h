#ifndef __GAC_X11CAIRO_XLIB_CAIRO_WINDOW_H
#define __GAC_X11CAIRO_XLIB_CAIRO_WINDOW_H

#include <GacUI.h>
#include "XlibIncludes.h"
#include "../Common/X11Window.h"

namespace vl
{
	namespace presentation
	{
		namespace x11cairo
		{
			namespace xlib
			{
				class XlibWindow : public Object, public IX11Window
				{
				protected:
					Display *display;
					Window window;
					WString title;
					elements::IGuiGraphicsRenderTarget* renderTarget;
					bool resizable, doubleBuffer, customFrameMode, visible;
					collections::List<INativeWindowListener*> listeners;
					XdbeBackBuffer backBuffer;
					XlibWindow* parentWindow;
					Rect bounds;
					Size clientSize;

					void UpdateTitle();
					void UpdateResizable();
					void GetParentList(collections::List<Window>&);

				public:
					XlibWindow(Display *display);

					virtual ~XlibWindow();

					//Internal methods
					Display *GetDisplay();
					Window GetWindow();
					void CheckDoubleBuffer();
					void RebuildDoubleBuffer();
					bool GetDoubleBuffer();
					XdbeBackBuffer GetBackBuffer();
					void SwapBuffer();

					void SetRenderTarget(elements::IGuiGraphicsRenderTarget*);

					elements::IGuiGraphicsRenderTarget* GetRenderTarget();

					void MouseUpEvent(MouseButton button, NativeWindowMouseInfo info);
					void MouseDownEvent(MouseButton button, NativeWindowMouseInfo info);
					void MouseMoveEvent(NativeWindowMouseInfo info);
					void MouseEnterEvent();
					void MouseLeaveEvent();
					void ResizeEvent(int width, int height);
					void VisibilityEvent(Window window);

					//GacUI Implementations
					virtual Rect GetBounds();

					virtual void SetBounds(const Rect &bounds);

					virtual Size GetClientSize();

					virtual void SetClientSize(Size size);

					virtual Rect GetClientBoundsInScreen();

					virtual WString GetTitle();

					virtual void SetTitle(WString title);

					virtual INativeCursor *GetWindowCursor();

					virtual void SetWindowCursor(INativeCursor *cursor);

					virtual Point GetCaretPoint();

					virtual void SetCaretPoint(Point point);

					virtual INativeWindow *GetParent();

					virtual void SetParent(INativeWindow *parent);

					virtual bool GetAlwaysPassFocusToParent();

					virtual void SetAlwaysPassFocusToParent(bool value);

					virtual void EnableCustomFrameMode();

					virtual void DisableCustomFrameMode();

					virtual bool IsCustomFrameModeEnabled();

					virtual WindowSizeState GetSizeState();

					virtual void Show();

					virtual void ShowDeactivated();

					virtual void ShowRestored();

					virtual void ShowMaximized();

					virtual void ShowMinimized();

					virtual void Hide();

					virtual bool IsVisible();

					virtual void Enable();

					virtual void Disable();

					virtual bool IsEnabled();

					virtual void SetFocus();

					virtual bool IsFocused();

					virtual void SetActivate();

					virtual bool IsActivated();

					virtual void ShowInTaskBar();

					virtual void HideInTaskBar();

					virtual bool IsAppearedInTaskBar();

					virtual void EnableActivate();

					virtual void DisableActivate();

					virtual bool IsEnabledActivate();

					virtual bool RequireCapture();

					virtual bool ReleaseCapture();

					virtual bool IsCapturing();

					virtual bool GetMaximizedBox();

					virtual void SetMaximizedBox(bool visible);

					virtual bool GetMinimizedBox();

					virtual void SetMinimizedBox(bool visible);

					virtual bool GetBorder();

					virtual void SetBorder(bool visible);

					virtual bool GetSizeBox();

					virtual void SetSizeBox(bool visible);

					virtual bool GetIconVisible();

					virtual void SetIconVisible(bool visible);

					virtual bool GetTitleBar();

					virtual void SetTitleBar(bool visible);

					virtual bool GetTopMost();

					virtual void SetTopMost(bool topmost);

					virtual void SupressAlt();

					virtual bool InstallListener(INativeWindowListener *listener);

					virtual bool UninstallListener(INativeWindowListener *listener);

					virtual void RedrawContent();
				};
			}
		}
	}
}

#endif
