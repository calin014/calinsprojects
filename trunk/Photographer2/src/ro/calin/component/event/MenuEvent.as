package ro.calin.component.event
{
	import flash.events.Event;
	
	import ro.calin.component.model.MenuEntryModel;
	
	[Bindable]
	/**
	 * Event for the menu component.
	 * Can hold a reference to a menu entry.
	 */
	public class MenuEvent extends Event
	{
		public static const MENU_ITEM_CLICK:String = "itemClick";
		public static const MENU_ITEM_HOVER:String = "itemHover";
		public static const MENU_LOGO_CLICK:String = "logoClick";
		
		public var entry:MenuEntryModel;
		public var buttonIndex:int;
		
		public function MenuEvent(type:String, entry:MenuEntryModel=null, index:int=0,
								  bubbles:Boolean=false, cancelable:Boolean=false)
		{
			super(type, bubbles, cancelable);
			this.entry = entry;
			this.buttonIndex = index;
		}
	}
}