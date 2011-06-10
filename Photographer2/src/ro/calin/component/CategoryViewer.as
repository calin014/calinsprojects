package ro.calin.component
{
	import flash.events.MouseEvent;
	
	import mx.collections.ArrayCollection;
	
	import ro.calin.component.event.CategoryEvent;
	import ro.calin.component.model.CategoryViewerModel;
	import ro.calin.component.skin.CategoryViewerSkin;
	
	import spark.components.DataGroup;
	import spark.components.supportClasses.SkinnableComponent;
	
	/**
	 * Component which can display a vertical thumbnail strip.
	 * The viewport is limited to the height and it can be
	 * scrolled by moving the mouse towords the components top
	 * or bottom.
	 */
	[Event(name="categItemClick", type="ro.calin.component.event.CategoryEvent")]
	public class CategoryViewer extends SkinnableComponent
	{
		/**
		 * This is the group of thumbnails.
		 */
		[SkinPart(required="true")]
		public var thumbnailStrip:DataGroup;
		
		private var _model:CategoryViewerModel;
		
		public function CategoryViewer() {
			setStyle("skinClass", CategoryViewerSkin);
		}
		
		[Bindable]
		public function set model(value:CategoryViewerModel):void {
			_model = value;
			
			//set the provider for the data group
			if(thumbnailStrip != null) {
				thumbnailStrip.dataProvider = _model.subcategories;
				//TODO: exept!!!!!!!! if model is changed from small to big
//				thumbnailStrip.verticalScrollPosition = maxScroll();
			}
		}
		
		public function get model():CategoryViewerModel {
			//create one to avoid npe in skin
			if(_model == null) _model = new CategoryViewerModel();
			
			return _model;
		}
		
		override protected function partAdded(partName:String, instance:Object) : void {
			super.partAdded(partName, instance);
			
			if(instance == thumbnailStrip) {
				if(_model != null) {
					thumbnailStrip.dataProvider = _model.subcategories;
//					thumbnailStrip.verticalScrollPosition = maxScroll();
				}
				thumbnailStrip.addEventListener(MouseEvent.MOUSE_MOVE, thumbnailStrip_mouseMoveHandler);
				thumbnailStrip.clipAndEnableScrolling = true;
			}
		}
		
		override protected function partRemoved(partName:String, instance: Object) : void {
			super.partRemoved(partName, instance);
			
			if(instance == thumbnailStrip) {
				thumbnailStrip.removeEventListener(MouseEvent.MOUSE_MOVE, thumbnailStrip_mouseMoveHandler);
			}
		}
		
		private function thumbnailStrip_mouseMoveHandler(evt:MouseEvent):void {
			//why is thumbnailStrip.contentHeight == thumbnailStrip.height???
			
			var fr:Number = (thumbnailStrip.contentHeight - this.height) / this.height;
			var scroll:Number = fr * evt.stageY - fr * this.y;
			
			var ms:Number = maxScroll();
			if(scroll > ms) scroll = ms;
			
			thumbnailStrip.verticalScrollPosition = scroll;
		}
		
		private function maxScroll():Number {
			return thumbnailStrip.contentHeight - thumbnailStrip.height;
		} 
	}
}