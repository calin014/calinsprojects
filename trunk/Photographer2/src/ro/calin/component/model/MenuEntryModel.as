package ro.calin.component.model
{
	import mx.collections.ArrayList;
	import mx.collections.IList;

	/**
	 * The model for the menu component.
	 * Besides the usual properties, it contains a
	 * generic object to hold various data if needed 
	 * and a list of subentries.
	 * */
	public class MenuEntryModel
	{
		public var label:String = "noname";
		public var color:uint = 0x000000;
		public var fontColor:uint = 0xffffff;
		public var fontSize:Number = 30;
		
		public var extra:Object = null;
		
		[Listof(type="ro.calin.component.model.MenuEntryModel")]
		public var entries:IList = null;
	}
}