import { ComponentFixture, TestBed } from "@angular/core/testing";

import { MdLoverComponent } from "./md-lover.component";

describe("MdLoverComponent", () => {
  let component: MdLoverComponent;
  let fixture: ComponentFixture<MdLoverComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [MdLoverComponent],
    }).compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(MdLoverComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it("should create", () => {
    expect(component).toBeTruthy();
  });
});
